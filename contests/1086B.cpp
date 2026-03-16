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
    int n, k, p, m;
    cin >> n >> k >> p >> m;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];

    int wCost = a[p];

    int setup = 0;
    if (p > k) {
        vector<int> before;
        for (int i = 1; i < p; i++) before.push_back(a[i]);
        sort(before.begin(), before.end());
        for (int i = 0; i < p - k; i++) setup += before[i];
    }

    int cycleAdv = 0;
    if (n > k) {
        vector<int> nonW;
        for (int i = 1; i <= n; i++) if (i != p) nonW.push_back(a[i]);
        sort(nonW.begin(), nonW.end());
        for (int i = 0; i < n - k; i++) cycleAdv += nonW[i];
    }

    int cycleCost = cycleAdv + wCost;

    if (m < setup + wCost) {
        cout << 0 << "\n";
        return;
    }
    cout << 1 + (m - setup - wCost) / cycleCost << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}