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
    vector<int> arr(n+1);
    for (int i=1;i<=n;i++) cin >> arr[i];

    for (int r=1;r<=n;r+=2){
        vector<int> values, index;
        for (int x=r;x<=n;x*=2){
            values.push_back(arr[x]);
            index.push_back(x);
        }
        sort(values.begin(),values.end());
        sort(index.begin(),index.end());
        if (values != index){
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}