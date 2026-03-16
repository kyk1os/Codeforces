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
    ll s, k, m;
    cin >> s >> k >> m;

    ll q = m / k;
    ll rem = m % k;

    ll r;
    if (s <= k) {
        r = s;
    } else {
        r = (q % 2 == 0 ? s : k); 
    }

    ll ans;
    if (rem == 0) ans = r;            
    else ans = max(0LL, r - rem);    

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