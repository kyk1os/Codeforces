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
    int n;
    cin >> n;

    vector<ll> a(n);
    map<ll, int> mp;
    ll sum = 0;

    for (auto &x : a) {
        cin >> x;
        sum += x;
        mp[x]++;
    }

    int mx = 0;
    ll val = 0;
    for (auto [x, c] : mp) {
        if (c > mx) {
            mx = c;
            val = x;
        }
    }

    if (mx > (n + 1) / 2) {
        int extra = mx - (n - mx) - 2;
        if (extra > 0) sum -= 1LL * extra * val;
    }

    cout << sum << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}