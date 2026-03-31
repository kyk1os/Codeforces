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
    int n; cin >> n;
    vector<int> a(n), b(n);
    for (int i=0;i<n;i++) cin >> a[i];
    for (int j=0;j<n;j++) cin >> b[j];

    ll mn = 0, mx = 0;
    for (int i = 0; i < n; i++) {
        mx = max(mx - a[i], b[i] - mn);
        mx = min(mn - a[i], b[i] - mx);
    }
    cout << mx << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}