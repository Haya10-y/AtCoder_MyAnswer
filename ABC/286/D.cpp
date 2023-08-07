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

//問題文：https://atcoder.jp/contests/abc286/tasks/abc286_d
/*
解答方針
ありうる状態をいろいろ考えてみよう。
ここで重要なこととして、硬貨の種類にかかわらず、今まで払った金額のみを考えればよいということが挙げられる。
また、sum(B_i) <= 2500であり、X <= 10000であることから、これらをかけあわせてもせいぜい2.5*10^7である。
よって、O(sum(B_i)*X)が間に合うため、NとB_iとXについてDPを回せばよい。
DPを回すときは、Xについて上から下に回そう。同じ硬貨を一度に2回以上使うことを防ぐためである。
*/

int main(){
  ll n,x;
  cin >> n >> x;
  vector<ll> a(n), b(n);
  rep(i,n){
    cin >> a[i] >> b[i];
  }
  vector<bool> dp(x+1,false);
  dp[0] = true;
  rep(i,n){
    rep(j,b[i]){
      rep_r(k,sz(dp)){
        if(dp[k] && k+a[i] <= x){
          //cout << k << " ";
          dp[k+a[i]] = dp[k];
        }
      }
    }
  }
  //cout << endl;
  /*rep(i,sz(dp)){
    cout << dp[i] << " ";
  }
  cout << endl;*/
  if(dp[x]){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }
}