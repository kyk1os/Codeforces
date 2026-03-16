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
    vector<string> s(n);
    for (int i = 0; i < n; i++) cin >> s[i];

    vector<pair<int,int>> edges;
    vector<vector<int>> adj(n);

    for (int u = 0; u < n; u++) {
        for (int v = 0; v < n; v++) {
            if (u == v || s[u][v] == '0') continue;
            bool direct = true;
            for (int w = 0; w < n && direct; w++)
                if (w != u && w != v && s[u][w] == '1' && s[w][v] == '1')
                    direct = false;
            if (direct) {
                edges.push_back({u + 1, v + 1});
                adj[u].push_back(v);
            }
        }
    }

    if ((int)edges.size() != n - 1) { cout << "No\n"; return; }

    vector<vector<int>> undirAdj(n);
    for (auto [u, v] : edges) {
        undirAdj[u-1].push_back(v-1);
        undirAdj[v-1].push_back(u-1);
    }
    vector<bool> vis(n, false);
    queue<int> q;
    q.push(0); vis[0] = true; int cnt = 1;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : undirAdj[u]) if (!vis[v]) { vis[v] = true; cnt++; q.push(v); }
    }
    if (cnt != n) { cout << "No\n"; return; }

    for (int start = 0; start < n; start++) {
        vector<bool> reach(n, false);
        stack<int> stk;
        stk.push(start); reach[start] = true;
        while (!stk.empty()) {
            int u = stk.top(); stk.pop();
            for (int v : adj[u]) if (!reach[v]) { reach[v] = true; stk.push(v); }
        }
        for (int j = 0; j < n; j++)
            if ((s[start][j] == '1') != reach[j]) { cout << "No\n"; return; }
    }

    cout << "Yes\n";
    for (auto [u, v] : edges) cout << u << " " << v << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}