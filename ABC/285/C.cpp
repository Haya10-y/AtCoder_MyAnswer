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

//問題文：https://atcoder.jp/contests/abc285/tasks/abc285_c
/*
解答方針
問題のIDは1問目から順にA,B,...,Z,AA,AB,...,AZ,AAA,...となります。
この桁の上がり方は数字に似ています。実際、26進数のようなものととらえてやるとすごくわかりやすいと思います。
下の桁から順に考えたとき、A = 1, B = 2, C = 3, ..., Z = 26とし、そこに26^桁数をかけてやると
すべての桁における変換後の値のを求めることができます。
これの総和がIDとなります。なお、値が大きくなる可能性があるため64bit整数を使うようにしましょう。
*/

int main(){
  string s;
  cin >> s;
  ll ans = 0;
  rep_r(i,sz(s)){
    ll n = sz(s)-i-1;
    ll num = s[i] - 'A' + 1;
    ll tmp = 1;
    rep(j,n){
      tmp *= 26;
    }
    tmp *= num;
    ans += tmp;
  }
  cout << ans << endl;
}