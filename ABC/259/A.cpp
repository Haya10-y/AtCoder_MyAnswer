#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(ll i = 0; i < n; i++)
#define rep_s(i,s,n) for(ll i = s; i < n; i++)
#define rep_r(i,n) for(ll i = n-1; i >= 0; i--)

//問題文：https://atcoder.jp/contests/abc259/tasks/abc259_a
/*
解答方針
もちろん年齢を直接計算してO(1)で解いてもよいですが、ここではループを用いた解答方法を提示します。
高橋くんはX歳の誕生日までの間、身長がDcmずつ伸びています。ただし、それ以外では伸びていません。
X <= Nより、X歳の身長とN歳の身長は同じであるため、この情報から0歳の身長を求めることができます。
0歳の身長を求めたあとは、M歳とX歳のうち、小さい方をとったうえで1年にDcmずつ伸ばしていきます。
これはforループで行うことができます。もちろんO(1)で直接計算してもよいですし、制約の値が大きければ直接計算一択でしょう。
*/

int main(){
  ll n,m,x,t,d;
  cin >> n >> m >> x >> t >> d;
  ll ans = t-x*d;
  rep(year, min(m,x)){
    ans += d;
  }
  
  cout << ans << endl;
}