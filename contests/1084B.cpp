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
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    int full = (1 << n) - 1;

    auto nondecreasing = [&](int mask) -> bool {
        int last = -1;
        bool has = false;
        for (int i = 0; i < n; ++i) {
            if ((mask >> i) & 1) {
                if (has && last > a[i]) return false;
                last = a[i];
                has = true;
            }
        }
        return true;
    };

    vector<char> vis(1 << n, 0);
    queue<int> q;
    q.push(full);
    vis[full] = 1;

    int ans = n;
    while (!q.empty()) {
        int mask = q.front();
        q.pop();

        if (nondecreasing(mask)) {
            ans = min(ans, __builtin_popcount(mask));
            continue;
        }

        for (int i = 0; i < n; ++i) {
            if ((mask >> i) & 1) {
                int nxt = mask ^ (1 << i);
                if (!vis[nxt]) {
                    vis[nxt] = 1;
                    q.push(nxt);
                }
            }
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