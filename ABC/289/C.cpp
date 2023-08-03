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

//問題文：
/*
解答方針
N,Mが小さく、2^M - 1 <= 1023であり、かつ集合の要素数は10以下であることから、全探索でも間に合いそうです。
ここでは、bit全探索というやや特殊な全探索を使います。
集合はbit列で表すことができ（0なら含まれない、1なら含まれる）、これを整数に置き換えて計算できることを覚えておくと便利です。
ありえる部分集合の数は2^M個になります。
これらの部分集合すべてについて、それらの要素をすべてマージしたものの中に1かNまでの数字が全て入っているか判定します。
条件を満たす部分集合の数が答えになります。ひとつずつカウントしていきましょう。
*/

int main(){
  ll n,m;
  cin >> n >> m;
  vector<vector<ll>>s(m);
  rep(i,m){
    ll c;
    cin >> c;
    rep(j,c){
      ll tmp;
      cin >> tmp;
      s[i].push_back(tmp);
    }
  }
  set<ll> st_ans;
  ll ans = 0;
  rep(i,n){
    st_ans.insert(i+1);
  }
  rep_b(bit,m){
    set<ll> st;
    rep(i,m){
      enum_bit(){
        rep(j,sz(s[i])){
          st.insert(s[i][j]);
        }
      }
    }
    if(st == st_ans){
      ans++;
    }
  }
  cout << ans << endl;
}