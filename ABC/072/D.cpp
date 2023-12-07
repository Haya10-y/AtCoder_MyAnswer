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
隣り合う二つの数を選び、swapを繰り返してi番目の要素がiにならないようにしたい。
ここで重要なこととして、i番目の要素がiのものはswapすると必ずiでなくなる。
左から順番に考えていけば最小手数で条件を達成できる。
ただし注意すべきこととして、隣り合う二つの数が両方順番と等しかった場合は1回のswapで両方が条件を満たすことがある。
*/
int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  int ans = 0;
  bool streak = false;
  rep(i,n){
    cin >> a[i];
    if(i+1 == a[i]){
      ans++;
      if(!streak){
        streak = true;
      }else{
        ans--;
        streak = false;
      }
    }else{
      streak = false;
    }
  }
  cout << ans << endl;
}