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
    vector<vector<int>> blogs(n);
    for (int i = 0; i < n; ++i) {
        int l;
        cin >> l;
        blogs[i].resize(l);
        for (int j = 0; j < l; ++j) cin >> blogs[i][j];
    }

    vector<vector<int>> c(n);
    for (int i = 0; i < n; ++i) {
        unordered_set<int> used;
        for (int j = static_cast<int>(blogs[i].size()) - 1; j >= 0; --j) {
            int x = blogs[i][j];
            if (!used.count(x)) {
                used.insert(x);
                c[i].push_back(x);
            }
        }
    }

    unordered_set<int> seen;
    vector<char> taken(n, 0);
    vector<int> answer;

    while (true) {
        int best_idx = -1;
        vector<int> best_seq;

        for (int i = 0; i < n; ++i) {
            if (taken[i]) continue;
            vector<int> cur;
            for (int x : c[i]) {
                if (!seen.count(x)) cur.push_back(x);
            }
            if (cur.empty()) continue;

            if (best_idx == -1 || lexicographical_compare(cur.begin(), cur.end(), best_seq.begin(), best_seq.end())) {
                best_idx = i;
                best_seq = std::move(cur);
            }
        }

        if (best_idx == -1) break;
        taken[best_idx] = 1;
        for (int x : best_seq) {
            answer.push_back(x);
            seen.insert(x);
        }
    }

    for (int i = 0; i < static_cast<int>(answer.size()); ++i) {
        if (i) cout << ' ';
        cout << answer[i];
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