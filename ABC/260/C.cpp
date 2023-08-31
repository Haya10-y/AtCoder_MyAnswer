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

//問題文：https://atcoder.jp/contests/abc260/tasks/abc260_c
/*
解答方針
レベルnの赤い宝石を交換する関数とレベルnの青い宝石を交換する関数を作りましょう。
それぞれ交換することで赤い宝石と青い宝石が手に入るため、これをレベルが1になるまで繰り返します。
これは再帰関数を用いることで実装することができます。
なお、本回答では相互再帰という状態になっており、あとに書いたblue関数を先に書いたred関数で呼び出すときは
プロトタイプ宣言というものを行う必要があることに注意します。先にblue関数の型をつくっておきましょう。
*/

ll x,y;
void blue(ll,ll);
ll ans = 0;
void red(ll lv,ll num){
  if(lv == 1){
    return;
  }
  red(lv-1,num);
  blue(lv,num*x);
}

void blue(ll lv,ll num){
  if(lv == 1){
    ans += num;
    return;
  }
  red(lv-1,num);
  blue(lv-1,num*y);
  
}

int main(){
  ll n;
  cin >> n >> x >> y;
  red(n,1);
  cout << ans << endl;
}