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

static const char CH[3] = {'R', 'G', 'B'};

bool check(const string& s, const array<int, 3>& orig) {
    array<int, 3> cnt = {0, 0, 0};
    for (char ch : s) {
        if (ch == 'R') cnt[0]++;
        else if (ch == 'G') cnt[1]++;
        else cnt[2]++;
    }
    for (int i = 0; i < 3; i++) {
        if (cnt[i] > orig[i]) return false;
    }
    for (int i = 0; i + 1 < (int)s.size(); i++) {
        if (s[i] == s[i + 1]) return false;
    }
    for (int i = 0; i + 3 < (int)s.size(); i++) {
        if (s[i] == s[i + 3]) return false;
    }
    return true;
}

string build_even(int a, int b, int c, char A, char B, char C) {
    int x = (b + c - a) / 2;
    string res;
    res.reserve(a + b + c);
    for (int i = 0; i < x; i++) {
        res += B;
        res += C;
    }
    for (int i = 0; i < c - x; i++) {
        res += A;
        res += C;
    }
    for (int i = 0; i < b - x; i++) {
        res += A;
        res += B;
    }
    return res;
}

void solve() {
    array<int, 3> orig;
    cin >> orig[0] >> orig[1] >> orig[2];

    array<int, 3> used = orig;
    int sum = used[0] + used[1] + used[2];
    int mx_id = max_element(used.begin(), used.end()) - used.begin();
    int others = sum - used[mx_id];
    if (used[mx_id] > others + 1) {
        used[mx_id] = others + 1;
    }

    int N = used[0] + used[1] + used[2];
    vector<int> p = {0, 1, 2};

    if (N % 2 == 0) {
        sort(p.begin(), p.end());
        do {
            int a = used[p[0]], b = used[p[1]], c = used[p[2]];
            if (!(a >= b && b >= c)) continue;
            if (a > b + c) continue;
            string ans = build_even(a, b, c, CH[p[0]], CH[p[1]], CH[p[2]]);
            if ((int)ans.size() == N && check(ans, orig)) {
                cout << ans << '\n';
                return;
            }
        } while (next_permutation(p.begin(), p.end()));
    } else {
        for (int tail = 0; tail < 3; tail++) {
            if (used[tail] == 0) continue;
            array<int, 3> rem = used;
            rem[tail]--;
            sort(p.begin(), p.end());
            do {
                int a = rem[p[0]], b = rem[p[1]], c = rem[p[2]];
                if (!(a >= b && b >= c)) continue;
                if (a > b + c) continue;
                string ans = build_even(a, b, c, CH[p[0]], CH[p[1]], CH[p[2]]);
                ans += CH[tail];
                if ((int)ans.size() == N && check(ans, orig)) {
                    cout << ans << '\n';
                    return;
                }
            } while (next_permutation(p.begin(), p.end()));
        }
    }

    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}