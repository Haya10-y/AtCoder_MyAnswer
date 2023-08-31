#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i,n) for(ll i = 0; i < n; i++)
#define rep_s(i,s,n) for(ll i = s; i < n; i++)
#define rep_r(i,n) for(ll i = n-1; i >= 0; i--)
#define rep_rs(i,s,e) for(ll i = s-1; i >= e; i--)
#define rep_b(bit,n) for (ll bit = 0; bit < (1<<n); bit++)
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

//問題文：https://atcoder.jp/contests/abc194/tasks/abc194_e
/*
解答方針
もしかしたら入出力の高速化によって正解している問題かもしれない。
N <= 1.5*10^6にもかかわらずO(NlogN)の解法を通しているため注意。
内容としてはM個のかたまりをとってそのmexを求め、ひとつ右に動かしたうえでまたmexを求め…ということを繰り返し、
mexの最小値をとりたい、という問題である。
mexはsetを使うと割と簡単に求められる。はじめにすべての整数を入れ、
今のmexの対象をsetから消していく、という処理を行う。
setについての計算量としてはO(NlogN)になる。
また、mexの対象となる要素の個数を把握したいため、ここにはmapを使う。

1回目の処理ではM個の要素をmexの対象とし、そのぶんsetから消し、mapにカウントを保存していく。
mexの答えはsetの一番最初の値であり、ここはO(1)で求められる。
また、2回目以降の処理ではsetへの出し入れはたかだか2回であり、1回ごとの計算量はO(logN)であるため、
全体の計算量はO(NlogN)程度で終わらせることができる。が、制約上かなりギリギリである。
*/

int main(){
  fast();
  int n,m;
  cin >> n >> m;
  vector<int> a(n);
  rep(i,n){
    cin >> a[i];
  }
  //mapで個数管理、setでmexの管理？1ずつ動かされるのでsetの計算量はO(NlogN)程度か
  //mapに関しては0 -> 1になったときにsetを消し、1 -> 0になったときにsetに入れる
  
  map<int,int> mp;
  set<int> st;
  rep(i,n+2){
    st.insert(i); //n = 1500000でO(NlogN)だと380ms程度、残り3620msも猶予がある
    //O(logN)は21回あれば終わるのでsetの出し入れはいけそう
  }
  int ans = 1e8;
  
  //1回目の処理
  rep(i,m){ //0 ~ m-1まで入れる
    if(mp[a[i]] == 0){
      st.erase(a[i]);
    }
    mp[a[i]]++;
    
  }
  ans = min(ans, *st.begin());
  
  //2回目以降の処理
  rep_s(i,m,n){ //mからスタートしてnまでやる
    //i-m個目を消し、i個目を入れる
    if(mp[a[i]] == 0){
      st.erase(a[i]);
    }
    mp[a[i]]++;
    if(mp[a[i-m]] == 1){
      st.insert(a[i-m]);
    }
    mp[a[i]]--;
    ans = min(ans, *st.begin());
  }
  cout << ans << endl;
}