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
#include <iomanip>

using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<int> c(n), p(n);
    for (int i = 0; i < n; i++) cin >> c[i] >> p[i];

    double f = 0;
    for (int i = n - 1; i >= 0; i--)
        f = max(f, c[i] + (1.0 - p[i] / 100.0) * f);

    cout << fixed << setprecision(10) << f << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}