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

//問題文：https://atcoder.jp/contests/abc313/tasks/abc313_c
/*
解答方針
まず、最終盤面から考えましょう。
Aの最小値と最大値の差を1以下にするということは、すなわちAの要素は全要素の平均値になるということです。
ただし、切り下げと切り上げが当然あるため、そこを考慮した上で考えます。
このとき、切り上げか切り下げかのどちらかの個数もとっておきましょう。
あとはAをソートして、小さい方あるいは大きい方から目的の値になるように解いていけばよいです。
例えば小さい方から解く場合、Aを昇順ソートしたうえで切り下げの個数分計算したのち、
残りを切り上げの値に向かわせるように解いてやればよいです。
配列のソートがボトルネックとなり、計算量はO(NlogN)です。
問題文では2回の操作を1回としているため、答えは操作カウントを2で割ったものを出力することに注意しましょう。
*/

int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i,n){
    cin >> a[i];
  }
  ll sum = 0;
  rep(i,n){
    sum += a[i];
  }
  ll avg_low = sum/n;
  ll avg_high = avg_low+1;
  ll highcnt = sum-avg_low*n;
  ll lowcnt = n-highcnt;
  ll ans = 0;
  sort(all(a)); //ソート
  rep(i,n){
    if(i < lowcnt){
      ans += abs(a[i]-avg_low);
    }else{
      ans += abs(a[i]-avg_high);
    }
  }
  cout << ans/2 << endl;
}