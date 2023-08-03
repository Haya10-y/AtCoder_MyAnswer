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
#define mod1 998244353
#define mod2 1000000007

//問題文：https://atcoder.jp/contests/abc289/tasks/abc289_d
/*
解答方針
典型的なDP問題。
階段の何段目が到達可能か、という1次元DPで解くことができる。
登る段数はX段までで動作の種類はN種類なので、NX回ループすれば十分である。
登った先にモチがあった場合はそこは踏めないため、ここを高速に判定してやる必要がある。
モチの座標を表すBをsetでもっておけば、「この位置にモチは存在するか？」という問題にはO(logM)で答えられる。
今回の場合、計算量はO(NXlogM + M)程度になった。モチがあるかどうかを座標ごとに見ればO(NX + M)程度で済む。
*/


int main(){
  ll n;
  cin >> n;
  vector<ll> a(n);
  rep(i,n){
    cin >> a[i];
  }
  ll m;
  cin >> m;
  set<ll> b;
  rep(i,m){
    ll tmp;
    cin >> tmp;
    b.insert(tmp);
  }
  ll x;
  cin >> x;
  vector<bool> dp(x+1,false);
  dp[0] = true;
  rep(i,x){
    rep(j,n){
      if(dp[i] && a[j]+i <= x && !b.count(a[j]+i)){
        //cout << a[j]+i << " ";
        dp[a[j]+i] = true;
      }
    }
  }
  //cout << endl;
  /*rep(i,x+1){
    cout << dp[i] << " ";
  }
  cout << endl;*/
  if(dp[x]){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }
}