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
#define debug_st(x,y) cerr << x << " " << y << " "
#define debug_p(p) cerr << p.first << " " << p.second << endl
#define all(a) a.begin(),a.end()
#define sz(v) ((ll)v.size())
#define eps 0.00001
#define PI 3.14159265358979323846264338
#include <atcoder/all>
using namespace atcoder;

//問題文：https://atcoder.jp/contests/abc271/tasks/abc271_a
/*
解答方針
この問題ではかなりアクロバティックなことをしています。
そのままコードを見てもわからないので、ASCIIコードの対応表をチェックしましょう。
https://www.k-cube.co.jp/wakaba/server/ascii_code.html

まず、16^1の位から決めます。これはn/16で求めることができます。
基本的には'0'にこの値を足してやればよいですが、ここで'9'の次は'A'でなく、':'であることに注意します。
n/16が10以上なら、'9'から7個飛ばした次の値の'A'に移動させるべく、7を足してつじつまを合わせます。
16^0の位も同様に決めることができます。char型と数字との対応は覚えておきましょう。
*/

int main(){
  ll n;
  cin >> n;
  char c1 = '0' + n/16;
  if(c1 >= ':'){
    c1 += 7;
  }
  char c2 = '0' + n%16;
  if(c2 >= ':'){
    c2 += 7;
  }
  cout << c1 << c2 << endl;
}