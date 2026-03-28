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

const int MOD = 67676767;
const int MAXN = 200000;
vector<int> dcnt(MAXN + 1);

void solve() {
    int x, y;
    cin >> x >> y;
    int s = abs(x - y);
    if (s == 0) {
        cout << 1 % MOD << '\n';
        for (int i = 0; i < x; i++) {
            if (i) cout << ' ';
            cout << 1;
        }
        for (int i = 0; i < y; i++) {
            if (x || i) cout << ' ';
            cout << -1;
        }
        cout << '\n';
        return;
    }

    cout << dcnt[s] % MOD << '\n';
    if (x > y) {
        for (int i = 0; i < x; i++) {
            if (i) cout << ' ';
            cout << 1;
        }
        for (int i = 0; i < y; i++) {
            if (x || i) cout << ' ';
            cout << -1;
        }
    } else {
        for (int i = 0; i < y; i++) {
            if (i) cout << ' ';
            cout << -1;
        }
        for (int i = 0; i < x; i++) {
            if (y || i) cout << ' ';
            cout << 1;
        }
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int i = 1; i <= MAXN; i++) {
        for (int j = i; j <= MAXN; j += i) dcnt[j]++;
    }

    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}