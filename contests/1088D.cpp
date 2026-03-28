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

const int MOD = 1e9 + 7;
const int MAXN = 100005;

ll fact[MAXN], invFact[MAXN];

ll power(ll base, ll exp) {
    ll res = 1;
    base %= MOD;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp /= 2;
    }
    return res;
}

ll modInverse(ll n) {
    return power(n, MOD - 2);
}

void precompute() {
    fact[0] = 1;
    invFact[0] = 1;
    for (int i = 1; i < MAXN; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
    }
    invFact[MAXN - 1] = modInverse(fact[MAXN - 1]);
    for (int i = MAXN - 2; i >= 1; i--) {
        invFact[i] = (invFact[i + 1] * (i + 1)) % MOD;
    }
}

ll nCr(int n, int r) {
    if (r < 0 || r > n) return 0;
    return fact[n] * invFact[r] % MOD * invFact[n - r] % MOD;
}

void solve() {
    int n;
    cin >> n;
    vector<ll> b(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }

    vector<int> c(30, 0);

    for (int k = n; k >= 1; k--) {
        if (b[k] > 0) {
            ll mask = b[k];
            for (int j = 0; j < 29; j++) {
                if ((mask >> j) & 1) {
                    c[j] = k;
                }
            }
            for (int i = 1; i <= k; i++) {
                ll sub = (mask * nCr(k, i)) % MOD;
                b[i] = (b[i] - sub + MOD) % MOD;
            }
        }
    }

    vector<int> a(n, 0);
    for (int j = 0; j < 29; j++) {
        for (int i = 0; i < c[j]; i++) {
            a[i] |= (1 << j);
        }
    }

    for (int i = 0; i < n; i++) {
        cout << a[i] << (i == n - 1 ? "" : " ");
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    precompute();
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}