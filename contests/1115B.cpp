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
    string s;
    cin >> s;

    int cnt0 = 0, cnt1 = 0;
    int B0 = 0, B1 = 0;

    for (int i = 0; i < n; ++i) {
        if (s[i] == '0') cnt0++;
        else cnt1++;

        if (i == 0 || s[i] != s[i - 1]) {
            if (s[i] == '0') B0++;
            else B1++;
        }
    }

    int delta = cnt0 - cnt1;
    if (abs(delta) > 2) {
        cout << -1 << "\n";
        return;
    }

    int B = B0 + B1;
    int max_k = -1;

    if (abs(delta) <= 1) {
        max_k = max(max_k, B - (B % 2));
    }
    
    if (abs(delta - 1) <= 1 && B0 > 0) {
        max_k = max(max_k, 2 * B0 - 1);
    }
    
    if (abs(delta - (-1)) <= 1 && B1 > 0) {
        max_k = max(max_k, 2 * B1 - 1);
    }

    if (max_k == -1) {
        cout << -1 << "\n";
    } else {
        cout << n - max_k << "\n";
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