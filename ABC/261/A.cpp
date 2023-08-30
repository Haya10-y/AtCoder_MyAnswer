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
#define all(a) a.begin(),a.end()
#define sz(v) ((ll)v.size())

//問題文：https://atcoder.jp/contests/abc261/tasks/abc261_a
/*
解答方針
かなりトリッキーな問題です。
どのように被覆しているのかということを条件分岐して考えるとよいですが、条件の数が多いので気をつけましょう。
紙に書いたうえですべての条件を洗い出し、それに応じた処理をしましょう。
*/

int main(){
  ll l1,r1,l2,r2;
  cin >> l1 >> r1 >> l2 >> r2;
  ll ans;
  if(r1 < l2){
    cout << 0 << endl;
    return 0;
  }
  
  if(l1 <= l2 && l2 <= r1 && r1 <= r2){
    ans = r1-l2;
  }else if(l2 <= l1 && l1 <= r2 && r2 <= r1){
    ans = r2-l1;
  }else if(l1 <= l2 && l2 <= r2 && r2 <= r1){
    ans = r2-l2;
  }else if(l2 <= l1 && l1 <= r1 && r1 <= r2){
    ans = r1-l1;
  }else{
    ans = 0;
  }
  cout << ans << endl;
}