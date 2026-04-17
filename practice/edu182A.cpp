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
    vector<int> a(n+1),pre(n+1);
    for (int i=1;i<=n;i++){
        cin >> a[i];
        pre[i]=pre[i-1]+a[i];
    }

    for (int l=1;l<=n-2;l++){
        for (int r=l+1;r<=n-1;r++){
            int s1=pre[l]%3;
            int s2=(pre[r]-pre[l])%3;
            int s3=(pre[n]-pre[r])%3;

            if ((s1==s2 && s2==s3) || (s1!=s2 && s1!=s3 && s2!=s3)){
                cout << l << ' ' << r << "\n";
                return;
            }
        }
    }
    cout << 0 << ' ' <<  0 << "\n";

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}