#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i,n) for(int i = 0; i < n; i++)
#define rep_s(i,s,n) for(int i = s; i < n; i++)
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
#define mint modint998244353
#define mod1 998244353
#define mod2 1000000007

//問題文：https://atcoder.jp/contests/abc280/tasks/abc280_e
/*
解答方針
通常攻撃とクリティカルで確率DPしよう。
modint998244353をつかって除算すると確率 mod 998244353が求まるため、ここは気にしなくてよい。
DPの添字を与えるダメージと考えてHPの低い状態から高い状態まで持って行ってもよいし、
敵の残りHPと考えてHPの高い状態から低い状態に持って行ってもよい。ここは好みの問題だろう。
*/

//reference: https://drken1215.hatenablog.com/entry/2022/12/07/113800
int main(){
  int n,p;
  cin >> n >> p;
  vector<mint> dp(n+1,0); //dp[i] -> 体力がiのモンスターのHPを0以下にするのに必要な攻撃回数の期待値
  rep_s(i,1,n+1){
    //体力を2減らすときと1減らすときで場合分け、modの世界ではP/QとするとR*Q≡PとなるRを返す？
    //HPの低い状態から高い状態 (N) まで持っていく
    //crit -> dp[i-2]*p/100, attack -> dp[i-1]*(100-p)/100
    dp[i] = (dp[max(i-2,0)] + 1) * mint(p) / 100 + (dp[i-1] + 1) * mint(100-p) / 100;
  }
  cout << dp[n].val() << endl;
}