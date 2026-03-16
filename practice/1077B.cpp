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
    string s2=s;
    if (n==1) {cout << 1 << "\n"; return;}
    if (n>=2){
        if (s[0]=='1') s2[1]='1';
        if (s[n-1]=='1') s2[n-2]='1';
        for (int i=1;i<n-1;i++){
            if (s[i]=='1'){
                s2[i-1]='1';
                s2[i+1]='1';
            }
        }
    }
    
    vector<int> lens;
    for (int i = 0; i < n; ) {
        if (s2[i] == '1') { 
            i++; 
            continue; 
        }
        int j = i;
        while (j < n && s2[j] == '0') j++;
        lens.push_back(j - i);   
        i = j;                   
    }

    int sum=0;
    for (int k=0;k<lens.size();k++){
        sum+=(lens[k]+2)/3;
    }

    for (int x=0;x<n;x++){
        sum+=(s[x]-'0');
    }
    cout << sum << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}