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
    vector<ll> a(n),b(n);
    for (int i=0;i<n;i++) cin >> a[i];
    b=a;

    for (int i=1;i<n;i++){
        b[i]=max(b[i-1],b[i]);
    }

    ll ans=0;
    for (int i=0;i<n;i+=2){
        ll lim;
        if (i==0) lim=b[1]-1;
        else lim=b[i-1]-1;

        if (a[i]>lim) ans+=a[i]-lim;
    }

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}