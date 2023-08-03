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
 
//QCFium法
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
 
void fast(){
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
}
 
#define endl "\n" //flushのとき外す

//問題文：https://atcoder.jp/contests/abc296/tasks/abc296_c
/*
要素の差がちょうどXになるようなものがあるか判定する問題です。
普通に二重ループでやろうとするとTLEしてしまうため、少し考えてみましょう。
ここで、配列の順番は変わっても一切問題ないため、ソートしても大丈夫です。
A_i - A_j = Xであることから、つまりA_i - X = A_jとなるA_jを探せ、という問題に置き換えられます。
ソート済みの配列から目的の値を探すためには二分探索を用いればよいため、合計の計算量はO(NlogN)におさまります。
*/

int main(){
  fast();
  ll n,x;
  cin >> n >> x;
  vector<ll> a(n);
  rep(i,n){
    cin >> a[i];
  }
  map<ll,ll> mp;
  //a[i]-a[j] = x.
  sort(all(a));
  //a[j] = a[i]-x;
  rep(i,n){
    ll target = a[i]-x;
    if(binary_search(all(a), target)){
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
}