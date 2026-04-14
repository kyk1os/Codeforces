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
    int n,k; cin >> n >> k;
    vector<int> a(k),b(n);
    for (int i=0;i<k;i++) cin >> a[i];
    for (int i=0;i<n;i++) cin >> b[i];

    vector<int> ans;
    while (true){
        int id=-1;
        for (int i=0;i<n;i++){
            if (b[i]==k+1) continue;
            if (id==-1 || b[i]>b[id]) id=i;
        }
        if (id==-1) break;
        ans.push_back(id+1);
        b[id]++;
    }
    cout << ans.size() << "\n";
    for (auto ele:ans){
        cout << ele << ' ';
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}