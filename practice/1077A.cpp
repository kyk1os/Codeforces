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
    vector<int> arr;
    arr.reserve(n);

    int lo=1,hi=n;
    while(lo<=hi){
        arr.push_back(hi);hi--;
        if(lo<=hi){
            arr.push_back(lo);lo++;
        }
    }

    reverse(arr.begin(),arr.end());
    for (auto ele: arr){
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