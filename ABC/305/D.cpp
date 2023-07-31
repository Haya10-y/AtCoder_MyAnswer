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

//問題文：https://atcoder.jp/contests/abc305/tasks/abc305_d
/*
解答方針
累積和と二分探索を併用する、ややテクニカルな問題です。典型力が問われます。
まず、時刻l,rを含む、最も近い点をとります。これは二分探索で求めることができます。
次にその区間における睡眠時間を求めます。これは事前に睡眠時間の累積和を求めておくことでO(1)で行えます。
あとは区間の左端からlまで、右端からrまでの睡眠時間を引けばよいです。
寝ている状態と起きている状態は交互に発生するため、寝ているかどうかの確認にはindexの偶奇を使うとよいでしょう。
合計の計算量はO(N+QlogN)となり、これは十分高速です。
*/

int main(){
  fast();
  int n;
  cin >> n;
  vector<ll> a(n);
  rep(i,n){
    cin >> a[i];
  }
  int q;
  cin >> q;
  vector<ll> l(q), r(q);
  rep(i,q){
    cin >> l[i] >> r[i];
  }
  vector<ll> sum(n,0); //とりあえず累積和
  rep_s(i,1,n){
    if(i%2 == 1){
      sum[i] = sum[i-1];
    }else{
      sum[i] = sum[i-1] + a[i]-a[i-1];
    }
  }
  /*rep(i,n){
    cout << sum[i] << " ";
  }
  cout << endl;*/
  
  rep(i,q){
    //とりあえずl,rを含む最も近い点をとりたい
    auto iter_l = lower_bound(all(a), l[i]);
    if(iter_l != a.begin()){
      iter_l--;
    }
    auto iter_r = lower_bound(all(a), r[i]);
    //cout << *iter_l << " " << *iter_r << endl;
    int idx_l = distance(a.begin(), iter_l);
    int idx_r = distance(a.begin(), iter_r);
    ll ans = sum[idx_r]-sum[idx_l];
    //cout << idx_l << " " << idx_r << " ";
    //cout << sum[idx_r] << " " << sum[idx_l] << " " << ans << " ";
    if(idx_l%2 == 1){
      ans -= l[i]-a[idx_l];
    }
    if(idx_r%2 == 0){
      ans -= a[idx_r]-r[i];
    }
    cout << ans << endl;
  }
}