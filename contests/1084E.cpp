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

vector<int> spf;

void build_spf(int mx) {
    spf.assign(mx + 1, 0);
    for (int i = 0; i <= mx; ++i) spf[i] = i;
    for (int i = 2; i * i <= mx; ++i) {
        if (spf[i] == i) {
            for (int j = i * i; j <= mx; j += i) {
                if (spf[j] == j) spf[j] = i;
            }
        }
    }
}

pair<int, bool> get_base_and_mixed(int x) {
    if (x == 1) return {1, false};
    int first = spf[x];
    int distinct = 0;
    while (x > 1) {
        int p = spf[x];
        ++distinct;
        while (x % p == 0) x /= p;
        if (distinct >= 2) return {first, true};
    }
    return {first, false};
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    if (is_sorted(a.begin(), a.end())) {
        cout << "Bob\n";
        return;
    }

    vector<int> base(n);
    for (int i = 0; i < n; ++i) {
        auto [b, mixed] = get_base_and_mixed(a[i]);
        if (mixed) {
            cout << "Alice\n";
            return;
        }
        base[i] = b;
    }

    cout << (is_sorted(base.begin(), base.end()) ? "Bob\n" : "Alice\n");
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    build_spf(1000000);

    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}