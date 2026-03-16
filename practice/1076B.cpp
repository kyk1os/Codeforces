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
    vector<int> arr(n);
    for (int i=0;i<n;i++) cin >> arr[i];

    int start, end;
    for (int r=0;r<n;r++){
        if (arr[r] != n-r) {start = r; break;}
    }
    for (int x=0;x<n;x++){
        if (arr[x]==n-start) {end = x; break;}
    }

    vector<int> newarr(n);
    for (int j=0;j<n;j++){
        if (start<=j && j<=end) newarr[j]=arr[start+end-j];
        else newarr[j]=arr[j];
    }
    for (auto k : newarr) cout << k << ' ';
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}