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
    ll n,x,y; cin >> n >> x >> y;
    vector<ll> arr(n);
    for (int i=0;i<n;i++) cin >> arr[i];

    ll sum=0;
    for (int j=0;j<n;j++){
       sum+=arr[j]/x;
    }
    
    ll money=0;
    for (int k=0;k<n;k++){
        ll current_val=(sum-arr[k]/x)*y+arr[k];
        money=max(money,current_val);
    }
    cout << money << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}