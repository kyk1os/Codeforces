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
    int n,s,x;
    cin >> n >> s >> x;
    vector<int> arr(n);
    for (int i=0;i<n;i++) cin >> arr[i];

    int sum = 0;
    for (int r=0;r<n;r++){
        sum+=arr[r];
    }
    
    cout << ((sum<=s && (s-sum)%x==0)? "YES\n":"NO\n");
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}