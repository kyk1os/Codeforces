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
    string s; cin >> s;
    int n=s.size();

    for (int i=0;i<n-1;i++){
        if (s[i]!='<' && s[i+1]!='>'){
            cout << -1 << "\n"; return;
        }
    }

    int left=0, right=0;
    bool havestar=false;
    for (char c:s){
        if (c=='<') left++;
        else if (c=='>') right++;
        else havestar=true;
    }

    cout << max(left,right)+(havestar ? 1:0) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}