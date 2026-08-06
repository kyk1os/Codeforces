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
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    if (n == 1) {
        cout << a[0] << "\n";
        return;
    }
    
    vector<ll> d(n - 1);
    for (int i = 0; i < n - 1; ++i) {
        d[i] = a[i + 1] - a[i];
    }
    
    int i = 0;
    while (i < n - 1) {
        int j = i;
        while (j < n - 1 && abs(d[j] % 2) == abs(d[i] % 2)) {
            j++;
        }
        sort(d.begin() + i, d.begin() + j);
        i = j;
    }
    
    cout << a[0];
    ll curr = a[0];
    for (int k = 0; k < n - 1; ++k) {
        curr += d[k];
        cout << " " << curr;
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}