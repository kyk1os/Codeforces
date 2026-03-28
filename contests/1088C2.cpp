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
    vector<int> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];

    vector<int> need(n + 1, 0);
    for (int i = 1; i <= k; i++) need[a[i]]++;

    bool ok = true;
    int free_cnt = 0;

    for (int r = 1; r <= k; r++) {
        vector<int> pos;
        for (int j = r; j <= n; j += k) pos.push_back(j);

        bool same = true;
        for (int i = 1; i < (int)pos.size(); i++) {
            if (a[pos[i]] != a[pos[0]]) same = false;
        }

        if (!same) {
            for (int j : pos) {
                if (b[j] != -1 && b[j] != a[j]) ok = false;
            }
            need[a[r]]--;
            if (need[a[r]] < 0) ok = false;
        } else {
            int val = -1;
            for (int j : pos) {
                if (b[j] != -1) {
                    if (val == -1) val = b[j];
                    else if (val != b[j]) ok = false;
                }
            }
            if (val == -1) {
                free_cnt++;
            } else {
                need[val]--;
                if (need[val] < 0) ok = false;
            }
        }
    }

    int rem = 0;
    for (int v = 1; v <= n; v++) rem += need[v];
    if (rem != free_cnt) ok = false;

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