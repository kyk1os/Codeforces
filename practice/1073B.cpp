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

int countnum(vector<int> array,int number){
    int count=0;
    for (int j=0;j < array.size();j++){
        if (array[j]==number){
            count++;
        }
    }
    return count;
}

void solve() {
    int n; cin >> n;
    vector<int> arr(n);
    for (int i=0;i<n;i++) cin >> arr[i];
    
    if (countnum(arr,0)==0){
        cout << "NO\n";
        return;
    }
    if (countnum(arr,0)>0 && countnum(arr,1)>0){
        cout << "YES\n";
        return;
    }
    if (countnum(arr,0)>0 && countnum(arr,1)==0){
        if (countnum(arr,0)==1){cout << "YES\n";}
        else{cout << "NO\n";}
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