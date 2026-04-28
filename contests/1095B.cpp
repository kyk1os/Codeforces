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
    int n;cin>>n;
    vector<int> p(n);
    for(int i=0;i<n;i++) cin >> p[i];

    int ans=0;
    for(int i=0;i+1<n;i++)
        if(gcd(p[i],p[i+1])==abs(p[i]-p[i+1])) ans++;
    cout << ans <<"\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}