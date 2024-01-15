#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i,n) for(int i = 0; i < n; i++)
#define rep_s(i,s,n) for(int i = s; i < n; i++)
#define rep_r(i,n) for(int i = n-1; i >= 0; i--)
#define rep_rs(i,s,e) for(int i = s-1; i >= e; i--)
#define rep_b(bit,n) for (int bit = 0; bit < (1<<n); bit++)
#define enum_bit() if(bit & (1<<i))
#define all(a) a.begin(),a.end()
#define sz(v) ((ll)v.size())
#define eps 0.00001
#define PI 3.14159265358979323846264338
#include <atcoder/all>
using namespace atcoder;
const int mod1 = 998244353;
const int mod2 = 1000000007;
#define mint modint998244353
#define mint2 modint1000000007
//QCFium法
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

void fast(){
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
}

#define endl "\n" //flushのとき外す

/*
解答方針
頂点1を削除するためには，頂点1が葉である必要がある．
つまり次数が1であることが条件になるため，頂点1から伸びる部分木を (頂点1の次数-1) 個だけ消してやる必要がある．
消す順序としてはサイズの小さい順から消すと最適になる．
部分木のサイズは頂点1と隣接した頂点からそれぞれDFSすることで求めることができる．
あとは小さい順から (頂点1の次数-1) 個のサイズの和を求め，最後に頂点1の分を足してやれば答えになる．
なお，逆を言うと一番大きな部分木を残し，Nからその部分木のサイズを引いても正解になる．
*/

long long pow_ll(long long x, long long n) {
    long long ret = 1;
    while (n > 0) {
        if (n & 1) ret *= x;  // n の最下位bitが 1 ならば x^(2^i) をかける
        x *= x;
        n >>= 1;  // n を1bit 左にずらす
    }
    return ret;
}

int main(){
  fast();
  int n;
  cin >> n;
  vector<vector<int>> g(n);
  int u,v;
  int deg1 = 0;
  rep(i,n-1){
    cin >> u >> v;
    u--;v--;
    g[u].push_back(v);
    g[v].push_back(u);
    if(u == 0 || v == 0){
      deg1++;
    }
  }
  //1から伸びる部分木のサイズをそれぞれ見る
  stack<int> st;
  vector<bool> passed(n,false);
  vector<int> alltree;
  int treesize = 0;
  int node;
  passed[0] = true;
  for(auto i: g[0]){
    //DFSを行う
    treesize = 0;
    st.push(i);
    passed[i] = true;
    while(!st.empty()){
      node = st.top();
      st.pop();
      treesize++;
      for(auto j: g[node]){
        if(!passed[j]){
          st.push(j);
          passed[j] = true;
        }
      }
    }
    alltree.push_back(treesize);
  }
  //deg1-1個の部分木を消して頂点1も消す
  sort(all(alltree));
  /*for(auto i: alltree){
    cout << i << endl;
  }*/
  int ans = 1;
  rep(i,deg1-1){
    ans += alltree[i];
  }
  cout << ans << endl;
}