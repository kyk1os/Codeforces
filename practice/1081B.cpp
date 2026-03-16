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
    string s; cin >> s;

    int B=(count(s.begin(),s.end(),'1'))%2;
    int T;
    if (n%2==0) T=B;
    else{
        if (B==1){
            cout << -1 << "\n";
            return;
        }
        T=0;
    }

    vector<int> arr;
    for (int j=0;j<n;j++){
        int b=s[j]-'0';
        int x_j=(T+b)%2;
        if (x_j==1) arr.push_back(j+1);
    }

    cout << arr.size() << "\n";
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