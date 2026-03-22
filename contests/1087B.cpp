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
    cin>>n;
    vector<ll>a(n);
    for(auto&x:a)cin>>x;
    for(int i=0;i<n;i++){
        int L=0,R=0;
        for(int j=i+1;j<n;j++){
            if(a[j]<a[i])L++;
            else if(a[j]>a[i])R++;
        }
        cout<<max(L,R);
        if(i<n-1)cout<<" ";
    }
    cout<<"\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}