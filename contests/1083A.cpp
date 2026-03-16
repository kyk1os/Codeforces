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
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];

    if (n == 1) {
        cout << a[1] << "\n";
        return;
    }

    int where = 1;
    for (int i = 1; i <= n; i++) {
        if (a[i] == n) { where = i; break; }
    }
    swap(a[1], a[where]);

    for (int i = 1; i <= n; i++) {
        cout << a[i] << (i == n ? '\n' : ' ');
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