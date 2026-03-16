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
    // vector //
    vector<int> arr;
    vector<int> arr(6,10);
    vector<vector<int>> dp(5,vector<int> (6,10));
    vector<vector<vector<int>>> dp(5, vector<vector<int>> (6, vector<int> (4)));
    
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(3);
    int back = arr.back();// 取栈顶，== stk.top() //
    arr.pop_back();
    arr.clear();
    bool e = arr.empty();
    arr.resize(5);

    // stack //
    stack<double> stk;
    stk.push(1.0);
    stk.push(1.4);
    cout << stk.top() << "\n";
    stk.pop(); // 删除最后进入的也就是栈顶 //

    // queue //
    queue<int> que;
    que.push(1);
    que.push(2);
    que.push(3);
    int front = que.front();
    int back = que.back();
    que.pop(); // 删除第一个进去的 //
    int size = que.size();
    bool empty = que.empty();

    // priority queue for max// 
    priority_queue<int> pque;
    pque.push(1);
    cout << pque.top() << "\n"; // output the largest value //
    pque.push(3);
    pque.push(2);
    pque.push(4);
    pque.pop(); // delete the largest //

    // priority queue for min //
    priority_queue<int, vector<int>, greater<int>> pque2;
    pque.top(); // the smallest value //

    // set //
    set<int> st;
    st.insert(1);
    st.insert(2);
    st.insert(2); 
    st.insert(0); 
    st.erase(2);
    if (st.find(1) != st.end())
    {
        cout << "yes" << "\n";
    } //返回迭代器//
    st.count(1);
    st.size();
    st.clear();
    st.empty(); //增，删，查均为log(n), .size是O(1)//
    for (set<int>::iterator it = st.begin(); it != st.end(); ++it)
        cout << *it << "\n";
    for (auto &ele : st)
        cout << ele << "\n";

    // map //
    map<int, int> mp;
    mp[2] = 1;
    mp[1] = 3;
    mp[0] = 4;
    mp[99999] = 66666;
    if (mp.find(2) != mp.end()){
        cout << "yes" << "\n"; 
    }
    mp.erase(2);
    int count = mp.count(2);
    int size = mp.size();
    mp.clear();
    bool e = mp.empty(); //增，删，改，查都是log(n)//

    for (map<int,int>::iterator it = mp.begin(); it != mp.end(); ++it)
    {
        cout << it->first << ' ' << it->second << "\n";
    }

    for (auto &pr : mp)
    {
        cout << pr.first << ' ' << pr.second << "\n";
    } 

    // string //
    string s(100, '0');
    cin >> s;
    cout << s;
    s = "awa";
    s[0] = 'b';
    string s1 = "123", s2 = "123";
    
    // pair //
    pair<int,int> p1={1,2};
    cout << p1.first << ' ' << p1.second << "\n";
    pair<char, int> p2={'a', 2};




    






}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;  // uncomment for multiple test cases
    while (T--) solve();
    return 0;
}
