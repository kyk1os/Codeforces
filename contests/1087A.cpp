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
    ll n,c,k;
    cin>>n>>c>>k;
    vector<ll>a(n);
    for(auto&x:a)cin>>x;
    sort(a.begin(),a.end());
    for(int i=0;i<n;i++){
        if(a[i]<=c){
            ll use=min(k,c-a[i]);
            k-=use;
            c+=a[i]+use;
        }
    }
    cout<<c<<"\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}