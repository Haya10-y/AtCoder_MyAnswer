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
#define debug(x) cerr << x << endl
#define debug_s(x) cerr << x << " "
#define debug_t(x,y) cerr << x << " " << y << endl
#define debug_st(x,y) cerr << x << " " << y << " "
#define debug_p(p) cerr << p.first << " " << p.second << endl
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

//問題文：https://atcoder.jp/contests/abc294/tasks/abc294_d
/*
実装方針
何も考えずに解くと、O(QlogN)をC++でがんばる問題になります。
この問題では、setをつかって受付状況を確認します。
はじめに呼ばれる人をidx = 1とし、クエリごとに以下の処理を行います。
イベント1：setにidxを入れ、idxをインクリメントする。
イベント2：setからxを削除する。O(logN)で可能。
イベント3：setの一番最初を出力して消す。
NとQが若干大きいですが、C++ならまず間に合います。Rustなどでも大丈夫でしょう。
*/

int main(){
  fast();
  ll n,q;
  cin >> n >> q;
  ll idx = 0;
  set<ll> que;
  rep(i,q){
    ll num;
    cin >> num;
    if(num == 1){
      que.insert(idx);
      idx++;
    }else if(num == 2){
      ll x;
      cin >> x;
      x--;
      que.erase(x);
    }else{
      cout << *(que.begin())+1 << endl;
    }
  }
}