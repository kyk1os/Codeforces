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
    ll n;
    cin >> n;

    ll x = n;
    ll ans = 1;

    if (x % 2 == 0) {
        ans *= 2;
        while (x % 2 == 0) x /= 2;
    }
    for (ll p = 3; p * p <= x; p += 2) {
        if (x % p == 0) {
            ans *= p;
            while (x % p == 0) x /= p;
        }
    }
    if (x > 1) ans *= x;

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}