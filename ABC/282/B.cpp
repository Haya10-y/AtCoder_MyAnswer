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

//問題文：https://atcoder.jp/contests/abc282/tasks/abc282_b
/*
解答方針
N <= 30より、O(N^2 * M)が余裕で間に合うため、全探索して解きましょう。
それぞれのペアについて、全ての問題が解けるか見ていきます。
片方でもoがついていれば次に進み、両方xなら条件を満たさなくなります。
最後まで処理が終われば全問解けることになるため、ここでカウンタを1増やします。
*/

int main(){
  ll n,m;
  cin >> n >> m;
  vector<string> s(n);
  rep(i,n){
    cin >> s[i];
  }
  ll cnt = 0;
  rep(i,n){
    rep_s(j,i+1,n){
      rep(k,m){
        if(s[i][k] == 'x' && s[j][k] == 'x'){
          break;
        }
        if(k == m-1){
          cnt++;
          //cout << i << " " << j << endl;
        }
      }
    }
  }
  cout << cnt << endl;
}