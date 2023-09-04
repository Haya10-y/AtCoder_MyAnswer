#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(ll i = 0; i < n; i++)
#define rep_s(i,s,n) for(ll i = s; i < n; i++)
#define rep_r(i,n) for(ll i = n-1; i >= 0; i--)
#define rep_b(bit,n) for (ll bit = 0; bit < (1<<n); bit++)
#define enum_bit() if(bit & (1<<i))
#define debug(x) cerr << x << endl
#define debug_s(x) cerr << x << " "
#define debug_t(x,y) cerr << x << " " << y << endl
#define all(a) a.begin(),a.end()
#define sz(v) ((ll)v.size())

//問題文：https://atcoder.jp/contests/abc177/tasks/abc177_c
/*
解答方針
愚直にやると当然ですがTLEするため、O(N)の解法を考えてみましょう。
ここで、A_iに対してかける数はA_(i+1),A_(i+2),...,A_Nとなります。
最終的にその和をとるため、A_iに関する式をまとめるとA_i * (A_(i+1) + A_(i+2) + ... + A_N)となります。
このうち和の形で表されているほうは、累積和を用いることで前処理O(N)、クエリO(1)で処理できます。
よって累積和を使い、計算していきましょう。10^9+7で割ったあまりを求めることや、オーバーフローには十分注意してください。
*/

int main(){
  ll n;
  cin >> n;
  vector<ll> a(n);
  rep(i,n){
    cin >> a[i];
  }
  vector<ll> sum(n+1);
  sum[0] = 0;
  rep(i,n){
    sum[i+1] = sum[i]+a[i];
  }
  ll ans = 0;
  /*rep(i,n+1){
    cerr << sum[i] << " ";
  }*/
  rep(i,n){
    ans += a[i]*((sum[n]-sum[i+1])%1000000007);
    ans %= 1000000007;
    //cerr << ans << endl;
  }
  
  cout << ans << endl;
}