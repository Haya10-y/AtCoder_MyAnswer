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

//問題文：https://atcoder.jp/contests/abc287/tasks/abc287_d
/*
解答方針
（あとで入れます）
*/

int main(){
  string s,t;
  cin >> s >> t;
  string prime = s.substr(sz(s)-sz(t),sz(t));
  //cout << prime << endl;
  ll diff = 0;
  rep(i,sz(t)){
    if(prime[i] == t[i] || prime[i] == '?' || t[i] == '?'){
      
    }else{
      diff++;
    }
  }
  if(diff == 0){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }
  rep(i,sz(t)){
    if(prime[i] == t[i] || prime[i] == '?' || t[i] == '?'){
      diff++;
    }
    prime[i] = s[i];
    if(prime[i] == t[i] || prime[i] == '?' || t[i] == '?'){
      diff--;
    }
    if(diff == 0){
      cout << "Yes" << endl;
    }else{
      cout << "No" << endl;
    }
  }
}