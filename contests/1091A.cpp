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
    ll k;
    if (!(cin >> n >> k)) return;

    ll total_moves = 0;
    for(int i=0;i<n;++i) {
        int val;
        cin >> val;
        total_moves+=val;
    }

    bool can_win = false;
    if (total_moves % 2 != 0) {
        can_win = true;
    } else {
        if ((n*k)%2==0) {
            can_win = true;
        }
    }

    if(can_win) cout << "YES\n";
    else cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}