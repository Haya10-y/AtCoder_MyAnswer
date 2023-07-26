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

//問題文：https://atcoder.jp/contests/abc301/tasks/abc301_d
/*
解答方針
まず、Nから確定しているビット分を引くことで、未確定部分にどれだけの数値が入りうるのかがわかる。
あとは上の桁から順番に1が入るか考えて確定させていく。2のN乗を計算するときは1LLを左にN回ビットシフトすると楽だったりする。
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
  string s;
  ll n;
  cin >> s >> n;
  ll ans = 0;
  //まずわかっているところを引く
  rep(i,sz(s)){
    int digit = sz(s)-i-1;
    ll num = pow_ll(2,digit);
    //cout << num << endl;
    if(s[i] == '1'){
      n -= num;
      ans += num;
    }
  }
  if(n < 0){
    cout << -1 << endl;
    return 0;
  }
  rep(i,sz(s)){
    int digit = sz(s)-i-1;
    ll num = pow_ll(2,digit);
    //cout << num << endl;
    if(s[i] == '?'){
      if(num <= n){
        n -= num;
        ans += num;
      }
    }
  }
  cout << ans << endl;
}