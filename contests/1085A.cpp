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

    int mn = 0, mx = 0;
    int l = 0;

    while (l < n) {
        int r = l;
        while (r + 1 < n && !(s[r] == '0' && s[r + 1] == '0')) r++;

        int first = -1, last = -1;
        for (int i = l; i <= r; i++) {
            if (s[i] == '1') {
                if (first == -1) first = i;
                last = i;
            }
        }

        if (first != -1) {
            int len = last - first + 1;
            mx += len;
            mn += (len + 2) / 2;
        }

        l = r + 1;
    }

    cout << mn << ' ' << mx << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}