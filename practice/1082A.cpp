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
    ll x, y;
    cin >> x >> y;

    ll t = x - 2LL * y;              
    if (t < 0) {
        cout << "NO\n";
        return;
    }
    if (t % 3 != 0) {
        cout << "NO\n";
        return;
    }

    ll d = t / 3;                 
    if (y < 0) {
        
        if (d < -2LL * y) {
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}