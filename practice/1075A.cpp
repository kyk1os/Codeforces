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
    int n,h,l; cin >> n >> h >> l;
    vector<int> arr(n);
    for (int i=0;i<n;i++) cin >> arr[i];

    vector<int> arr2;
    for (int j=0;j<n;j++){
        if (arr[j]<=max(h,l)) arr2.push_back(arr[j]);
    }

    int count=0;
    for (int x=0;x<arr2.size();x++){
        if (arr2[x]<=min(h,l)){
            count++;
        }
    }

    if (count >= (arr2.size()/2)){
        cout << arr2.size()/2 << "\n";
    }
    else{
        cout << count << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}