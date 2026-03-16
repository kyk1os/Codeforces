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
    int n; cin >> n;
    string s; cin >> s;

    int count=0;
    bool adjequal=false;
    for (int i=0;i<n;i++){
        if (s[i]!=s[(i+1)%n]) count++;
        else adjequal=true;
    }
    
    int ans =(adjequal? count+1:count);
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