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

struct FenwickMax {
    int n;
    vector<int> bit;
    FenwickMax(int n=0){ init(n); }
    void init(int n_) { n = n_; bit.assign(n+1, 0); }
    void reset() { fill(bit.begin(), bit.end(), 0); }
    void update(int i, int v){
        for(; i<=n; i+=i&-i) bit[i] = max(bit[i], v);
    }
    int query(int i){
        int r = 0;
        for(; i>0; i-=i&-i) r = max(r, bit[i]);
        return r;
    }
};

static int best_keep_with_max_at_end(const vector<int>& v, int N) {
    int m = (int)v.size();
    vector<int> dec(m), inc(m);

    FenwickMax fw(N);

    for (int i = 0; i < m; i++) {
        int x = v[i];
        int bestGreater = fw.query(N - x);
        dec[i] = bestGreater + 1;
        fw.update(N - x + 1, dec[i]);
    }

    fw.reset();

    for (int i = m - 1; i >= 0; i--) {
        int x = v[i];
        int bestGreater = fw.query(N - x);
        inc[i] = bestGreater + 1;
        fw.update(N - x + 1, inc[i]);
    }

    int best = 1;
    for (int i = 0; i < m; i++) {
        best = max(best, dec[i] + inc[i] - 1);
    }
    return best;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    int posMax = -1;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] == n) posMax = i;
    }

    vector<int> pref(a.begin(), a.begin() + posMax + 1);
    int keep1 = best_keep_with_max_at_end(pref, n);
    int ans1 = n - keep1;

    vector<int> suf(a.begin() + posMax, a.end());
    reverse(suf.begin(), suf.end());
    int keep2 = best_keep_with_max_at_end(suf, n);
    int ans2 = n - keep2;

    cout << min(ans1, ans2) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}