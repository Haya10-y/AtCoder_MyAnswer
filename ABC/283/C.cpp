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
#define mod1 998244353
#define mod2 1000000007

//問題文：https://atcoder.jp/contests/abc283/tasks/abc283_c
/*
解答方針
表示される数は非常に大きくなることがありますが、よく考えれば整数型で処理する必要はありません。
また、0以外についてよく考える必要はありません。なぜなら、0以外の数字については押されるボタンは一意に定まるからです。
よって、0が2つ繋がっているときのみ00を押す、ということについて考えればよいです。
0がひとつ来たら保留し、もう一つ連続できたら00を入力、そうでなければ0と何かしらの数字を入力するような形になります。
もしくは、0がひとつきたらカウントを入れ、もうひとつ連続できたら押すボタンを0 -> 00に変え、カウントを増やさないようにするとよいです。
*/

int main(){
  string s;
  cin >> s;
  bool iszero = true;
  ll cnt = 0;
  rep(i,sz(s)){
    if(s[i] == '0'){
      if(!iszero){
        cnt++;
        iszero = true;
      }else{
        iszero = false;
      }
    }else{
      cnt++;
      iszero = false;
    }
  }
  cout << cnt << endl;
}