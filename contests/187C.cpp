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

static inline ll lowbit(ll x){ return x & -x; }

bool ok(ll n, ll s, ll m) {
    ll lo = 0, hi = 0; 

    for (int k = 0; k <= 62; k++) {
        int sb = (s >> k) & 1LL;
        int mb = (m >> k) & 1LL;

        if (!mb) {
            if ((lo & 1LL) != sb) lo++;
            if ((hi & 1LL) != sb) hi--;
            if (lo > hi) return false;

            lo = (lo -sb) /2;
            hi = (hi -sb) /2;
        } else {
            ll nlo = (ll)4e18, nhi = -1;

            for (int p = 0; p <= 1; p++) { 
                ll tmin = lo;
                if ((tmin & 1LL) != p) tmin++;
                if (tmin > hi) continue;

                ll tmax = hi;
                if ((tmax & 1LL) != p) tmax--;
                if (tmax < lo) continue;

                int cpar = sb ^ p;             
                ll cmin = cpar;                
                if (cmin > n) continue;

                ll cmax = (n & 1LL) == cpar ? n : (n - 1);
                if (cmax < 0) continue;

                ll out_lo = (tmin + cmin - sb) / 2;
                ll out_hi = (tmax + cmax - sb) / 2;

                nlo = min(nlo, out_lo);
                nhi = max(nhi, out_hi);
            }

            if (nhi < 0) return false;
            lo = nlo; hi = nhi;
        }
    }

    return (lo <= 0 && 0 <= hi);
}

void solve() {
    ll s, m;
    cin >> s >> m;

    ll g = lowbit(m);
    if (s % g != 0) {
        cout << -1 << "\n";
        return;
    }

    ll hi = s/g;          
    ll lo = 1;

    while (lo < hi) {
        ll mid = lo + (hi - lo) /2;
        if (ok(mid, s, m)) hi = mid;
        else lo = mid + 1;
    }
    cout << lo<<"\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}