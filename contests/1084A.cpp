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
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    vector<int> possible(n, 0);
    int total = accumulate(a.begin(), a.end(), 0);

    for (int s = 0; s < n; ++s) {
        vector<int> b = a;
        int rem = total;
        int i = s;
        int last = -1;
        while (rem > 0) {
            if (b[i] > 0) {
                --b[i];
                --rem;
                last = i;
            }
            i = (i + 1) % n;
        }
        possible[last] = 1;
    }

    cout << accumulate(possible.begin(), possible.end(), 0) << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}