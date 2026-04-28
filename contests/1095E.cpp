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

const int MAXL=1200005;
int tree_sum[4*MAXL];
int tree_min_suf[4*MAXL];
int C[MAXL];

void build(int node,int start,int end){
    tree_sum[node]=0;
    tree_min_suf[node]=0;
    if(start==end)return;
    int mid=start+(end-start)/2;
    build(2*node,start,mid);
    build(2*node+1,mid+1,end);
}

void update(int node,int start,int end,int idx,int val){
    if(start==end){
        tree_sum[node]+=val;
        tree_min_suf[node]=min(0,tree_sum[node]);
        return;
    }
    int mid=start+(end-start)/2;
    if(idx<=mid)update(2*node,start,mid,idx,val);
    else update(2*node+1,mid+1,end,idx,val);
    tree_sum[node]=tree_sum[2*node]+tree_sum[2*node+1];
    tree_min_suf[node]=min(tree_min_suf[2*node+1],tree_min_suf[2*node]+tree_sum[2*node+1]);
}

int get_idx(int x){
    return(x==0?-1:(x-1)/2)+1;
}

void solve(){
    int n;
    cin>>n;
    vector<int>a(n);
    int max_a=0;
    for(int i=0;i<n;i++){
        cin >> a[i];
        if(a[i]>max_a) max_a=a[i];
    }
    int L=max(n,max_a)+5;
    build(1,0,L);
    for(int i=0;i<=L;i++) C[i]=0;
    int M=0;
    for(int i=0;i<n;i++){
        int x=a[i];
        C[x]++;
        if (x<M){
            if(C[x]==1) update(1,0,L,x+1,+1);
            else update(1,0,L,get_idx(x),+1);
        }else update(1,0,L,get_idx(x),+1);
        while(true){
            int target=M;
            bool reverted=false;
            if(C[target]==0){
                update(1,0,L,target+1,-1);
                if (tree_min_suf[1]<0){
                    update(1,0,L,target+1,+1);reverted=true;
                }
            }else{
                update(1,0,L,get_idx(target),-1);
                if(tree_min_suf[1]<0){
                    update(1,0,L,get_idx(target),+1);reverted=true;
                }
            }
            if(reverted) break;
            M++;
        }
        cout << M << (i==n-1?"":" ");
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}