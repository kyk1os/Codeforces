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
    int len, spec;
    if(!(cin >> len >> spec)) {return;}

    vector<int> vals(len);
    for(int i=0;i<len;i++) cin >> vals[i];

    int target_idx;
    cin >> target_idx;
    target_idx--; 

    int v_goal = vals[target_idx];
    int l_req = 0;
    for(int i=0;i<target_idx;i++){
        if(l_req%2 != (vals[i] != v_goal)) {l_req++;}
    }

    int r_req = 0;
    for(int i=len-1;i>target_idx;i--){
        if(r_req%2 != (vals[i] != v_goal)) {r_req++;}
    }

    int total_ops = max(l_req, r_req);
    if(total_ops%2 != 0) {total_ops++;}
    
    cout << total_ops << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    if(!(cin >> T)) return 0;
    while (T--) solve();
    return 0;
}