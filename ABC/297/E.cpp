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
 
//QCFium法
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
 
void fast(){
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
}
 
#define endl "\n" //flushのとき外す

//問題文：https://atcoder.jp/contests/abc297/tasks/abc297_e
/*
解答方針
「同じたこ焼きを何個買ってもよい」というところから、たこ焼きの種類は少ないにもかかわらず、
高橋くんが支払う金額の種類はかなり大きくなってしまう。
そこで、まず1種類のたこ焼きをK個まで買うことを考えたあと、
これらすべての状態に対して、2種類目のたこ焼きを買ったとき、3種類目のたこ焼きを買ったとき…と考える。
setの中身はK個までしか入らないという条件から、あふれた分を毎回削除する実装をするとよい。
setの中身について、値の小さい順から1個たこ焼きを買ったときにどうなるか、ということを
すべての中身について考えるとsetが正しく更新されていく。
最後にsetの末尾を出力すればこの問題に正解できる。計算量はO(NKlogK)程度になる。
*/

set<ll> st;
int k;
void ins(ll a){
  st.insert(a);
  if(sz(st) == k+1){
    st.erase(prev(st.end()));
  }
}
 
int main(){
  fast();
  int n;
  cin >> n >> k;
  vector<int> a(n);
  rep(i,n){
    cin >> a[i];
  }
  sort(all(a));
  rep(i,n){
    ins(a[i]);
  }
  rep(i,k){
    ins(a[0]*(i+1));
  }
  ll mx = *prev(st.end());
  rep_s(i,1,n){ //i == 0のときは済んでいる
    for(auto j: st){
      ll tmp = j+a[i];
      if(tmp >= mx){
        break;
      }
      ins(tmp);
      mx = *prev(st.end());
    }
  }
  cout << *prev(st.end()) << endl;
}