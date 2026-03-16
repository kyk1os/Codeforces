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
    ll h;
    cin >> n >> h;

    vector<ll> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];

    vector<vector<ll>> mx(n + 2, vector<ll>(n + 2, 0));
    for (int l = 1; l <= n; l++) {
        ll cur = 0;
        for (int r = l; r <= n; r++) {
            cur = max(cur, a[r]);
            mx[l][r] = cur;
        }
    }

    vector<vector<ll>> pref(n + 2, vector<ll>(n + 2, 0));
    for (int p = 1; p <= n; p++) {
        for (int i = p; i <= n; i++) {
            pref[p][i] = pref[p][i - 1] + (h - mx[p][i]);
        }
    }

    vector<vector<ll>> suff(n + 2, vector<ll>(n + 3, 0));
    for (int q = 1; q <= n; q++) {
        for (int i = q; i >= 1; i--) {
            suff[q][i] = suff[q][i + 1] + (h - mx[i][q]);
        }
    }

    ll ans = 0;

    for (int p = 1; p <= n; p++) {
        for (int q = p; q <= n; q++) {
            int lo = p, hi = q, t = p - 1;
            while (lo <= hi) {
                int mid = (lo + hi) >> 1;
                if (mx[p][mid] <= mx[mid][q]) {
                    t = mid;
                    lo = mid + 1;
                } else {
                    hi = mid - 1;
                }
            }

            ll midPart = 0;
            if (t >= p) midPart += pref[p][t];
            if (t + 1 <= q) midPart += suff[q][t + 1];

            ll leftPart = (p > 1 ? suff[p][1] - suff[p][p] : 0);
            ll rightPart = (q < n ? pref[q][n] - pref[q][q] : 0);

            ans = max(ans, leftPart + midPart + rightPart);
        }
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}