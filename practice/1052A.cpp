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
    vector<int> a(n);
    for (int i=0;i<n;i++) cin >> a[i];

    vector<int> list(101,0);
    for (auto ele:a){
        list[ele]++;
    }
    
    int mx=*max_element(list.begin(),list.end());

    int ans=0;
    for (int k=1;k<=mx;k++){
        int num=0;
        for (int x=1;x<=100;x++){
            if (list[x]>=k) num++;
        }
        ans=max(ans,k*num);
    }
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