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
歩いて移動か、テレポートで移動の2通りある。
町1からどう動くのが最適であるかということを考えると、当然だが1からNまで順番にたどっていくのが早い。
1から2まで、2から3まで、...、N-1からNまでについて、どちらの移動方法が低コストであるか考えて計算していけばよい。
*/

int main(){
  ll n,a,b;
  cin >> n >> a >> b;
  vector<ll> x(n);
  rep(i,n){
    cin >> x[i];
  }
  ll ans = 0;
  rep(i,n-1){
    if((x[i+1]-x[i])*a <= b){
      ans += (x[i+1]-x[i])*a;
    }else{
      ans += b;
    }
  }
  cout << ans << endl;
}