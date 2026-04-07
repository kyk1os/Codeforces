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
    ll y_limit, x_limit, dy, dx;
    if(!(cin >> y_limit >> x_limit >> dy >> dx)) return;

    auto get_gcd = [](ll u, ll v) {
        while(v){u%=v;swap(u, v);}
        return u;
    };

    bool row_accessible = get_gcd(dy, y_limit) == 1;
    bool col_accessible = get_gcd(dx, x_limit) == 1;
    bool structure_ok = get_gcd(y_limit, x_limit) <= 2;

    if(row_accessible && col_accessible && structure_ok) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}