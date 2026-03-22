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

int ask(int i, int j) {
    cout << "? " << i << " " << j << "\n";
    cout.flush();

    int r;
    cin >> r;
    if (r == -1) exit(0);
    return r;
}

void answer(int k) {
    cout << "! " << k << "\n";
    cout.flush();
}

void solve() {
    int n;
    cin >> n;

    if (ask(1, 2) == 1) {
        answer(1);
        return;
    }
    if (ask(1, 3) == 1) {
        answer(1);
        return;
    }
    if (ask(2, 3) == 1) {
        answer(2);
        return;
    }

    for (int i = 4; i <= 2 * n - 1; i += 2) {
        if (ask(i, i + 1) == 1) {
            answer(i);
            return;
        }
    }

    answer(2 * n);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}