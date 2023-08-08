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

//問題文：
/*
解答方針
もちろん普通に解いてもよいですが、実装をミスする可能性があるためあまりおすすめしません。
そこで、正規表現をつかうことで条件を満たす文字列を楽に判定します。
正規表現を"[A-Z][1-9][0-9][0-9][0-9][0-9][0-9][A-Z]"とおくことで文字列が条件を満たすか確かめることができます。
*/

int main(){
  string s;
  cin >> s;
  if(sz(s) != 8){
    cout << "No" << endl;
    return 0;
  }
  regex reg("[A-Z][1-9][0-9][0-9][0-9][0-9][0-9][A-Z]");
  if(regex_search(all(s), reg)){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }
}