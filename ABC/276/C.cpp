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

//問題文：https://atcoder.jp/contests/abc276/tasks/abc276_c
/*
解答方針
順列全探索のときにnext_permutationはよく使いますが、prev_permutationはあまり使わないと思います。
言語のライブラリにあるprev_permutationを使うか、自力で実装しましょう。
他言語のprev_permutationの実装例を参考にするか、next_permutationの逆で考えましょう。
*/

int main(){
  ll n;
  cin >> n;
  vector<ll> p(n);
  rep(i,n){
    cin >> p[i];
  }
  prev_permutation(all(p));
  rep(i,n){
    cout << p[i] << " ";
  }
}