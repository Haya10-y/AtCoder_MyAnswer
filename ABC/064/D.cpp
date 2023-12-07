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

/*
解答方針
括弧列をつくる際、辞書順最小にするためにはなるべく左側に'('を、なるべく右側に')'を入れる必要がある。
まず、正しい括弧列をつくる必要があるため、')'が多く括弧列が成り立たない場合は埋め合わせとして'('を左側に出力する。
そのあともとの括弧列を出力し、最後に'('の余剰分だけ')'を出力すればよい。
*/

int main(){
  ll n;
  cin >> n;
  string s;
  cin >> s;
  ll diff = 0;
  rep(i,n){
    if(diff == 0 && s[i] == ')'){
      cout << '(';
    }else if(s[i] == '('){
      diff++;
    }else{
      diff--;
    }
  }
  cout << s;
  rep(i,diff){
    cout << ')';
  }
  cout << endl;
}