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
    int n, m;
    cin >> n >> m;
    vector<ll> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    vector<vector<ll>> a(n, vector<ll>(m));
    vector<ll> vals;
    vals.reserve(n * m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            vals.push_back(a[i][j]);
        }
    }

    sort(vals.begin(), vals.end());
    vals.erase(unique(vals.begin(), vals.end()), vals.end());

    int S = vals.size();
    vector<ll> tree_sum(4 * S, 0);
    vector<int> tree_count(4 * S, 0);

    auto update = [&](auto& self, int node, int l, int r, int idx, ll val) -> void {
        tree_sum[node] += val;
        tree_count[node]++;
        if (l == r) return;
        int mid = l + (r - l) / 2;
        if (idx <= mid) self(self, node * 2, l, mid, idx, val);
        else self(self, node * 2 + 1, mid + 1, r, idx, val);
    };

    auto query = [&](auto& self, int node, int l, int r, ll req) -> ll {
        if (req <= 0) return 0;
        if (tree_sum[node] < req) return 1e9;
        if (l == r) return (req + vals[l] - 1) / vals[l];
        int mid = l + (r - l) / 2;
        if (tree_sum[node * 2 + 1] >= req) {
            return self(self, node * 2 + 1, mid + 1, r, req);
        } else {
            return tree_count[node * 2 + 1] + self(self, node * 2, l, mid, req - tree_sum[node * 2 + 1]);
        }
    };

    ll ans = m;
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j < m; j++) {
            int idx = lower_bound(vals.begin(), vals.end(), a[i][j]) - vals.begin();
            update(update, 1, 0, S - 1, idx, a[i][j]);
        }
        ans = min(ans, query(query, 1, 0, S - 1, v[i]));
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}