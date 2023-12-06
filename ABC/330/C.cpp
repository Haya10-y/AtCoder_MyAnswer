#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i,n) for(int i = 0; i < n; i++)
#define rep_s(i,s,n) for(int i = s; i < n; i++)
#define rep_r(i,n) for(int i = n-1; i >= 0; i--)
#define rep_rs(i,s,e) for(int i = s-1; i >= e; i--)
#define rep_b(bit,n) for (int bit = 0; bit < (1<<n); bit++)
#define enum_bit() if(bit & (1<<i))
#define all(a) a.begin(),a.end()
#define sz(v) ((ll)v.size())
#define eps 0.00001
#define PI 3.14159265358979323846264338
#include <atcoder/all>
using namespace atcoder;
const int mod1 = 998244353;
const int mod2 = 1000000007;
#define mint modint998244353
#define mint2 modint1000000007
//QCFium法
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

void fast(){
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
}

#define endl "\n" //flushのとき外す

/*
解答方針
D <= 2*10^12であり、制約からO(sqrt(D))くらいで解く必要がありそう。
ここで、x^2およびy^2が必ず正の数になる、かつx^2はたかだか2*10^12付近になることから、xをsqrt(D)まで全探索すればよい。
xが決まればyの最適な値は自ずと求まるため、そのyについてx^2+y^2-Dの絶対値を求めていき、最小値を更新していく。
なお、sqrtの誤差が怖ければ周囲の値をとっておくことが安全策となる。
*/

int main(){
  fast();
  ll d;
  cin >> d;
  //x^2 <= 10^12となる最大のxはx=10^6
  //O(sqrt(D))で全部とれれば勝ち
  ll ans = 1e17;
  ll y;
  for(ll x = 0; x <= sqrt(d)+1; x++){
    //xを決めるとyの値は一意に定まるが、念のため周りをとっておく
    y = sqrtl(d-x*x);
    for(ll dy = -3; dy <= 3; dy++){
      ans = min(ans, abs(x*x+(y+dy)*(y+dy)-d));
    }
  }
  cout << ans << endl;
}