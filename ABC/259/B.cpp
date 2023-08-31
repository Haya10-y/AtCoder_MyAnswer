#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(ll i = 0; i < n; i++)
#define rep_s(i,s,n) for(ll i = s; i < n; i++)
#define rep_r(i,n) for(ll i = n-1; i >= 0; i--)

//問題文：https://atcoder.jp/contests/abc259/tasks/abc259_b
/*
解答方針
回転行列で調べてみましょう。いろいろ出てきます。
行列を計算すると、a'=acosd-bsind, b' = asind+bcosdとなります。
これを三角関数で計算してやり、答えを求めましょう。
ただし、dは弧度法に直す必要があることに注意しましょう。
また、値を出力する際には十分大きい桁数を出力するようにすると安全です。
*/

int main(){
  double a,b,d;
  cin >> a >> b >> d;
  double pi = 3.141592653589793238;
  d = d/180*pi;
  cout << setprecision(10) <<a*cos(d) - b*sin(d) << " " << a*sin(d) + b*cos(d) << endl;
}