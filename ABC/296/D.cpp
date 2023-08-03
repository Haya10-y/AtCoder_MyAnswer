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

//問題文：https://atcoder.jp/contests/abc296/tasks/abc296_d
/*
実装方針
普通にaとbの二重ループで全探索するとどうあがいてもまず間に合わない。a <= nの全探索でも間に合わない。
ここで、X >= M, X = abであることから、M <= abとなる（タイトル通り）。
ここで、聞かれている値はX = abだけであり、aとbの値を独立に聞かれているわけではないため、a <= bのときのみ考えればよい。
a > bの場合はa <= bの場合ですべてまかなえるからである。
あとはa > bになるまでaを全探索する。ここで、bはM <= abとなるbの最小値である。
大きくてもa,bは10^6くらいでおさまるため、計算量的にはO(sqrt(M))くらいになる。
*/

int main(){
  fast();
  ll n, m;
  cin >> n >> m;
  ll x = 9e18;
  ll xnull = x;
  
  rep_s(a,1,n+1){
    ll b = (m+a-1)/a; //ceil(m/a)が最小のbとなる
    if(b <= n){
      ll xtmp = a*b;
      x = min(x,xtmp); //bが条件を満たしたらxをchmin
    }
    if(a > b){ //aとbの組み合わせは可換であり、a <= bのときのみ考えればよい. sqrt(M)回+alphaで終わる
      break;
    }
  }
  
  if(x == xnull){
    cout << -1 << endl;
    return 0;
  }
  cout << x << endl;
}