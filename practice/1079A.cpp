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

int sumdigit(int y){
    int sum = 0;
    while (y>0){
        sum += (y%10);
        y/=10;
    }
    return sum;
}

void solve() {
    int x; cin >> x;
    int count = 0;
    for (int i=x;i<x+90;i++){
        if (i-sumdigit(i)==x){
            count +=1;
        }
    }
    cout << count << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}