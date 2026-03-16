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
    int n; string s;
    cin >> n >> s;
    set<int> vis;
    int pos = 0;
    vis.insert(pos);
    for (int i = 0; i < n; i++) {
        pos += (s[pos] == 'R') ? 1 : -1;
        vis.insert(pos);
    }
    cout << vis.size() << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}