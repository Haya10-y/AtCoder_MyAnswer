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

//問題文：https://atcoder.jp/contests/abc278/tasks/abc278_c
/*
解答方針
SNS依存の方々ならよりわかりやすいでしょう。ユーザーA_iとユーザーB_iがFF関係であるか見る問題です。
ユーザ数のNが大きいため、vectorで隣接リストをもっていては間に合いません。
ここで、クエリ数は2*10^5以下であるため、連想配列を使うことで計算量の削減ができます。
ユーザが誰をフォローしているかという情報を連想配列と集合で持つことで、
フォロー・フォロー解除、FFチェックを高速で行うことができます。
*/

int main(){
  ll n,q;
  cin >> n >> q;
  map<ll,set<ll>> mp;
  rep(i,q){
    ll t,a,b;
    cin >> t >> a >> b;
    if(t == 1){
      mp[a].insert(b);
    }else if(t == 2){
      mp[a].erase(b);
    }else if(t == 3){
      if(mp[a].count(b) != 0 && mp[b].count(a) != 0){
        cout << "Yes" << endl;
      }else{
        cout << "No" << endl;
      }
    }
  }
}