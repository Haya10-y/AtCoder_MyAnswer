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

//問題文：https://atcoder.jp/contests/abc286/tasks/abc286_b
/*
解答方針
Misskeyを使っている人ならなんとなく想像できるかと思います。naをnyaに変換する問題です。
変換の際には別の文字列を用意し、そこに入れていく方法が簡単です。
1文字目がnでなければそのまま入れ、nであれば2文字目を見ます。
2文字目がaであればnyaとして入れ、そうでなければ1文字目だけ入れます。
これを繰り返すことで変換することができます。
*/

int main(){
  ll n;
  cin >> n;
  string s;
  cin >> s;
  string t = "";
  rep(i,n){
    if(s[i] != 'n'){
      t.push_back(s[i]);
      continue;
    }
    if(s[i] == 'n' && i+1 < n && s[i+1] == 'a'){
      t += ("nya");
      i++;
      continue;
    }else{
      t.push_back(s[i]);
      continue;
    }
  }
  cout << t << endl;
}