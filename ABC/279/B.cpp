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

//問題文：https://atcoder.jp/contests/abc279/tasks/abc279_b
/*
解答方針
もちろんfor文を使って解いてもよいですが、ここではstringのfind関数を用いて解きます。
find関数を用いることで連続部分文字列を求めることができるため、これで問題を解くことができます。
連続部分文字列がない場合はstring::nposを返すので、返り値がこれであるかないかで判定できます。
*/

int main(){
  string s,t;
  cin >> s;
  cin >> t;
  if(s.find(t) != string::npos){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }
}