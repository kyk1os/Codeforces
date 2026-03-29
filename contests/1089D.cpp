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

int get_d(const string& s) {
    int n = s.length();
    if (n == 0) return 0;
    
    int P = 0;
    while (P < n && s[P] == '(') P++;
    
    int S = 0;
    while (S < n && s[n - 1 - S] == ')') S++;
    
    int max_d = min(P, S);
    if (P > n - 1 - S) return max_d;
    
    int min_bal = 1e9;
    int cur = 0;
    for (int i = 0; i < n; ++i) {
        cur += (s[i] == '(' ? 1 : -1);
        if (i >= P && i <= n - 1 - S) {
            min_bal = min(min_bal, cur);
        }
    }
    
    return min(max_d, min_bal);
}

int count_leaves(const string& s) {
    int cnt = 0;
    for (int i = 0; i < (int)s.length() - 1; ++i) {
        if (s[i] == '(' && s[i + 1] == ')') cnt++;
    }
    return cnt;
}

void solve() {
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    
    if (get_d(s) == get_d(t) && count_leaves(s) == count_leaves(t)) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}