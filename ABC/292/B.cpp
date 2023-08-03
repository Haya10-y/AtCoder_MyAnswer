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

//問題文：https://atcoder.jp/contests/abc292/tasks/abc292_b
/*
解答方針
連想配列mapを使って解くか、Nが小さいことを利用して通常の配列で全選手のカードカウントを見るかという方針が考えられます。
イエローカードならカウント+1、レッドカードならカウント+2したうえでカウントが2以上なら退場処分、という実装が簡単です。
*/

int main(){
  ll n,q;
  cin >> n >> q;
  map<ll,ll> mp;
  rep(i,q){
    ll num,x;
    cin >> num >> x;
    if(num == 1){
      mp[x]++;
    }else if(num == 2){
      mp[x] += 2;
    }else{
      if(mp[x] >= 2){
        cout << "Yes" << endl;
      }else{
        cout << "No" << endl;
      }
    }
  }
}