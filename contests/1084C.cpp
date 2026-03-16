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
    string s;
    cin >> n >> s;

    string st;
    st.reserve(n);
    for (char c : s) {
        if (!st.empty() && st.back() == c) st.pop_back();
        else st.push_back(c);
    }

    cout << (st.empty() ? "YES\n" : "NO\n");
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}