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
    string s;
    cin >> s;
    int n = s.size();
    
    for (int i = 0; i < n - 1; i++) {
        if (s[i] != '<' && s[i + 1] != '>') {
            cout << -1 << "\n";
            return;
        }
    }
    
    int a = 0, b = 0;
    bool star = false;
    for (char c : s) {
        if (c == '<') a++;
        else if (c == '>') b++;
        else star = true;
    }
    
    cout << max(a, b) + (star ? 1 : 0) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}