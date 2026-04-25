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

ll askwtfisI(ll x) {
    cout << "I " << x << endl;
    ll r;cin >> r;
    if(r==-1) exit(0);
    return r;
}

ll askwtfisQ(ll x) {
    cout << "Q " << x << endl;
    ll r;cin >> r;
    if(r==-1) exit(0);
    return r;
}

void answer(ll k,ll c) {
    cout << "A " << k << " " << c << endl;
}

ll findc(ll total) {
    ll l=1,r=total;
    while(l<r) {
        ll mid =(l+r+1)/2;
        ll got=askwtfisQ(mid);

        if(got >=1) l=mid;
        else r= mid-1;
    }
    return l;
}

void solve() {
    int n;cin >> n;
    ll all =(1LL<<n)-1;
    cout << 0 << endl;
    ll sz=askwtfisI(0);

    if(sz==1) {
        askwtfisI(all);
        ll c=findc(all);
        answer(1,c);
        return;
    }

    ll c=findc(all);

    if((c&(c-1))!=0) {
        ll x=c&-c;
        ll now=askwtfisI(x);
        if(now==2)answer(2,c);
        else answer(3,c);
        return;
    }
    askwtfisI(all);
    ll got=askwtfisQ(all);

    if(got==1) answer(2,c);
    else answer(3,c);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}