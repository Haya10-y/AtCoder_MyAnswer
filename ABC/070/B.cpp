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

/*
解答方針
両方ボタンを押していた時間を求める問題。
1回の計算で求めるか、シミュレーションを行うかの2択。
本回答では1回の計算で求めているが、場合分けが面倒なのでこのくらいならシミュレーションのほうが楽。
*/

int main(){
  int a,b,c,d;
  cin >> a >> b >> c >> d;
  int ans = 0;
  if(a <= c && c <= b && b <= d){
    ans = b-c;
  }else if(c <= a && a <= b && b <= d){
    ans = b-a;
  }else if(c <= a && a <= d && d <= b){
    ans = d-a;
  }else if(a <= c && c <= d && d <= b){
    ans = d-c;
  }
  cout << ans << endl;
}