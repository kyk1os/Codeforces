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
    vector<int> perm(n),arr(n);
    for (int i=0;i<n;i++) cin >> perm[i];
    for (int i=0;i<n;i++) cin >> arr[i];

    vector<int> box(n+1);
    for (int j=0;j<n;j++){
        box[perm[j]]=j;
    }

    for (int x=0;x<n-1;x++){
        if (box[arr[x]]>box[arr[x+1]]){
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