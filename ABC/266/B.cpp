#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i,n) for(ll i = 0; i < n; i++)
#define rep_s(i,s,n) for(ll i = s; i < n; i++)
#define rep_r(i,n) for(ll i = n-1; i >= 0; i--)
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
#define mod1 998244353
#define mod2 1000000007

//問題文：https://atcoder.jp/contests/abc266/tasks/abc266_b
/*
解答方針
解答に出してよい数字は 0~998244352 です。
Nが0以上であった場合は素直にNを998244353で割ったあまりを求めればよいです。
Nが0未満であった場合が問題で、言語によってあまりの仕様が異なる可能性があります。
そのため、たとえばC++などではN < 0のときに条件分岐をしてやりましょう。
*/

int main(){
  ll n;
  cin >> n;
  bool minus = false;
  if(n < 0){
    minus = true;
  }
  n = abs(n);
  n %= mod1;
  if(minus){
    cout << (mod1-n)%mod1 << endl;
  }else{
    cout << n%mod1 << endl;
  }
}