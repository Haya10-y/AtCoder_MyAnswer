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

//問題文：https://atcoder.jp/contests/abc291/tasks/abc291_a
/*
解答方針
char型の値は整数としてもとれるため、forループで1文字ずつ見て
'A' <= S_i <= 'Z'であるかどうか見ると楽です。
あるいは、AからZまですべて入れた配列をつくってS_iがその中にあるか見る、という方法でも解くことができます。
他にもいろいろな方法があると思うので、好きな解き方で解きましょう。
*/

int main(){
  string s;
  cin >> s;
  rep(i,sz(s)){
    if('A' <= s[i] && s[i] <= 'Z'){
      cout << i+1 << endl;
      return 0;
    }
  }
}