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
    vector<int> a(n + 1), b(n + 1), pos(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        pos[a[i]] = i;
    }
    for (int i = 1; i <= n; i++) cin >> b[i];

    int L = n - k + 1, R = k;
    bool ok = true;

    if (L > R) {
        for (int i = 1; i <= n; i++) {
            if (b[i] != -1 && b[i] != a[i]) ok = false;
        }
        cout << (ok ? "YES" : "NO") << '\n';
        return;
    }

    vector<int> used(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        if (i < L || i > R) {
            if (b[i] != -1 && b[i] != a[i]) ok = false;
        } else {
            if (b[i] != -1) {
                if (pos[b[i]] < L || pos[b[i]] > R) ok = false;
                if (used[b[i]]) ok = false;
                used[b[i]] = 1;
            }
        }
    }

    cout << (ok ? "YES" : "NO") << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}