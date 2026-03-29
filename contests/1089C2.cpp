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
    
    vector<ll> a(n), b(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> b[i];
    
    vector<ll> g(n - 1);
    for (int i = 0; i < n - 1; ++i) {
        g[i] = gcd(a[i], a[i + 1]);
    }
    
    vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 
        41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
    vector<vector<ll>> C(n);
    
    for (int i = 0; i < n; ++i) {
        C[i].push_back(a[i]);
        ll L;
        if (i == 0) L = g[0];
        else if (i == n - 1) L = g[n - 2];
        else L = lcm(g[i - 1], g[i]);
        
        if (L != a[i] && L <= b[i]) {
            C[i].push_back(L);
        } else if (L == a[i]) {
            for (int p : primes) {
                if (L > b[i] / p) break;
                C[i].push_back(L * p);
            }
        }
    }
    
    vector<vector<int>> dp(n);
    for (int i = 0; i < n; ++i) {
        dp[i].assign(C[i].size(), -1);
    }
    
    dp[0][0] = 0;
    for (int j = 1; j < C[0].size(); ++j) dp[0][j] = 1;
    
    for (int i = 1; i < n; ++i) {
        for (int k = 0; k < C[i - 1].size(); ++k) {
            if (dp[i - 1][k] == -1) continue;
            ll val_prev = C[i - 1][k];
            
            for (int j = 0; j < C[i].size(); ++j) {
                ll val_curr = C[i][j];
                if (gcd(val_prev, val_curr) == g[i - 1]) {
                    dp[i][j] = max(dp[i][j], dp[i - 1][k] + (j == 0 ? 0 : 1));
                }
            }
        }
    }
    
    int ans = 0;
    for (int j = 0; j < C[n - 1].size(); ++j) {
        ans = max(ans, dp[n - 1][j]);
    }
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