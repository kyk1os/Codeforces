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

int min_rotation_index(const vector<int>& a) {
    int n = static_cast<int>(a.size());
    if (n == 1) return 0;
    int i = 0, j = 1, k = 0;
    while (i < n && j < n && k < n) {
        int x = a[(i + k) % n];
        int y = a[(j + k) % n];
        if (x == y) {
            ++k;
            continue;
        }
        if (x > y) {
            i = i + k + 1;
            if (i <= j) i = j + 1;
        } else {
            j = j + k + 1;
            if (j <= i) j = i + 1;
        }
        k = 0;
    }
    return min(i, j);
}

void solve() {
    int n, x, y;
    cin >> n >> x >> y;
    vector<int> p(n);
    for (int i = 0; i < n; ++i) cin >> p[i];

    vector<int> mid;
    mid.reserve(y - x);
    for (int i = x; i < y; ++i) mid.push_back(p[i]);

    vector<int> out;
    out.reserve(n - (y - x));
    for (int i = 0; i < x; ++i) out.push_back(p[i]);
    for (int i = y; i < n; ++i) out.push_back(p[i]);

    int st = min_rotation_index(mid);
    int first_mid = mid[st];

    int k = 0;
    while (k < static_cast<int>(out.size()) && out[k] < first_mid) ++k;

    bool first = true;
    for (int i = 0; i < k; ++i) {
        if (!first) cout << ' ';
        cout << out[i];
        first = false;
    }
    for (int t = 0; t < static_cast<int>(mid.size()); ++t) {
        if (!first) cout << ' ';
        cout << mid[(st + t) % static_cast<int>(mid.size())];
        first = false;
    }
    for (int i = k; i < static_cast<int>(out.size()); ++i) {
        if (!first) cout << ' ';
        cout << out[i];
        first = false;
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}