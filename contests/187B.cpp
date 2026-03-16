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
    string x;
    cin >> x;
    int L = (int)x.size();

    const int INF = 1e9;
    vector<vector<int>> dp(L + 1, vector<int>(10, INF));
    dp[0][0] = 0;

    for (int i = 0; i < L; i++) {
        int cur = x[i] - '0';
        for (int s = 0; s <= 9; s++) {
            if (dp[i][s] >= INF) continue;
            int lo = (i == 0 ? 1 : 0);
            for (int d = lo; d <= 9; d++) {
                if (s + d > 9) break;
                int add = (d != cur);
                dp[i + 1][s + d] = min(dp[i + 1][s + d], dp[i][s] + add);
            }
        }
    }

    int ans = INF;
    for (int s = 1; s <= 9; s++) ans = min(ans, dp[L][s]);
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