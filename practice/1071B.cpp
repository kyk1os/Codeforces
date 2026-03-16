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

    vector<int> arr2;
    for (int r=0;r<n;r++){
        if (r==0) arr2.push_back(abs(arr[r]-arr[r+1]));
        else if (r>0 && r<n-1) 
            arr2.push_back(abs(arr[r]-arr[r-1])+abs(arr[r]-arr[r+1])-abs(arr[r-1]-arr[r+1]));
        else if (r==n-1) arr2.push_back(abs(arr[r]-arr[r-1]));
    }
    int mx = *max_element(arr2.begin(), arr2.end()); 

    int original_sum = 0;
    for (int j=0;j<n-1;j++){
        original_sum += abs(arr[j]-arr[j+1]);
    }
    int min_value = original_sum - mx;
    cout << min_value << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}