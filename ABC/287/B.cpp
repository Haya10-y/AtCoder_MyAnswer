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

//問題文：https://atcoder.jp/contests/abc287/tasks/abc287_b
/*
解答方針
N,Mの値が小さいため、全探索が通ります。
S_1についてT_1からT_Mまで探索を行い、ひとつでも一致するT_iがあればカウントを1足します。
S_2以降についても同様に行います。
計算量はO(NM)で、これは十分高速です。
*/

int main(){
  ll n,m;
  cin >> n >> m;
  vector<string> s(n),t(m);
  rep(i,n){
    cin >> s[i];
  }
  rep(i,m){
    cin >> t[i];
  }
  ll ans = 0;
  rep(i,n){
    rep(j,m){
      if(s[i].substr(3,3) == t[j]){
        ans++;
        break;
      }
    }
  }
  cout << ans << endl;
}