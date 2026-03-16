#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>

using namespace std;
using ll = long long;

void solve() {
    int n, m, l;
    cin >> n >> m >> l;

    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<int> gaps;
    gaps.reserve(n + 1);

    int prev = 0;
    for (int x : a) {
        gaps.push_back(x - prev);
        prev = x;
    }
    gaps.push_back(l - prev);

    vector<ll> v(m, 0);

    for (int idx = 0; idx <= n; idx++) {
        int remaining_flashes = n - idx;
        int k = min(m, remaining_flashes + 1);
        ll g = gaps[idx];

        vector<ll> u(v.begin(), v.begin() + k);
        sort(u.begin(), u.end());

        ll rem = g;
        for (int t = 0; t + 1 < k; t++) {
            ll need = (u[t + 1] - u[t]) * 1LL * (t + 1);
            if (rem >= need) {
                for (int i = 0; i <= t; i++) u[i] = u[t + 1];
                rem -= need;
            } else {
                ll q = rem / (t + 1);
                ll r = rem % (t + 1);
                for (int i = 0; i <= t; i++) {
                    u[i] += q + (i < r ? 1 : 0);
                }
                rem = 0;
                break;
            }
        }

        if (rem > 0) {
            ll q = rem / k;
            ll r = rem % k;
            for (int i = 0; i < k; i++) {
                u[i] += q + (i < r ? 1 : 0);
            }
        }

        sort(u.rbegin(), u.rend());
        for (int i = 0; i < k; i++) v[i] = u[i];

        if (idx < n) {
            v[0] = 0;
            sort(v.rbegin(), v.rend());
        }
    }

    cout << v[0] << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}