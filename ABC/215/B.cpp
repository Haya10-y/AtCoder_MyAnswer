#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

//問題文：
/*
解答方針
2^k <= Nとなる最大のkを求める問題です。kを増やしていき、
2^k > Nとなった時点で処理を止めて直前のkを出力しましょう。
なお、64bit整数であれば途中でオーバーフローする心配はありません（2*10^18 < 9*10^18 < LLONG_MAXより）。
また、2の冪乗を求めるときはpow関数ではなく1LL << kとしたほうがより安全です。
なぜならpow関数は浮動小数点数を返すため、誤差が発生しかねないからです（今回の場合は大丈夫）。
*/

int main(){
  ll n;
  cin >> n;
  ll k = 0;
  ll ans = 0;
  for(ll i = 0; i < 100000; i++){
    ans = pow(2,i);
    if(ans > n){
      cout << i-1 << endl;
      break;
    }
  }
  //cout << ans << endl;
}