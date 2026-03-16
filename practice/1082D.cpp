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
    int n, k;
    cin >> n >> k;

    int m = k - n;

    if (m < 0 || m > n - 1) {
        cout << "NO\n";
        return;
    }

    cout << "YES\n";

    if (m == 0) {
        for (int i = 1; i <= n; i++) {
            if (i > 1) cout << " ";
            cout << i << " " << i;
        }
        cout << "\n";
        return;
    }

    cout << 1 << " " << 2;
    for (int i = 1; i <= m - 1; i++) {
        cout << " " << (i + 2) << " " << i;
    }
    cout << " " << m << " " << (m + 1);

    for (int i = m + 2; i <= n; i++) {
        cout << " " << i << " " << i;
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    cin >> T;
    while (T--) solve();
    return 0;
}
