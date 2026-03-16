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
    ll a, b, c, m;
    cin >> a >> b >> c >> m;

    ll ab = lcm(a, b), ac = lcm(a, c), bc = lcm(b, c), abc = lcm(ab, c);

    ll A = m/a, B = m/b, C = m/c;
    ll AB = m/ab, AC = m/ac, BC = m/bc, ABC = m/abc;

    cout << 6*A - 3*AB - 3*AC + 2*ABC << " "
         << 6*B - 3*AB - 3*BC + 2*ABC << " "
         << 6*C - 3*AC - 3*BC + 2*ABC << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}