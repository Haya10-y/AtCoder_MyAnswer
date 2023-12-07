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
N!は1からNまでの数字をかけたものである。これは普通に求めるととてつもなく大きな数字になってしまう。
ここで、求めたいのはN!の正の約数の個数であるため、約数の個数を簡単に求められる方法を考えよう。
約数の個数を求めるためには、素因数分解が有効である。
そのため、O(N*sqrt(N))で1からNまでの素因数分解を行い、素因数の個数を足し合わせていこう。
あとはこれらの個数をかけあわせていけば約数の個数が求まる。1e9+7で割ったあまりを求めるのを忘れないように。
怖ければmodintを使ってしまうのが安全である。
*/

template <typename T>
map<T, T> prime_factor(T n) {
    map<T, T> ret;
    for (T i = 2; i * i <= n; i++) {
        T tmp = 0;
        while (n % i == 0) {
            tmp++;
            n /= i;
        }
        ret[i] = tmp;
    }
    if (n != 1) ret[n] = 1;
    return ret;
}

int main(){
  int n;
  cin >> n;
  mint2 ans = 1;
  map<int,int> primefactor;
  rep_s(i,1,n+1){
    auto tmp = prime_factor(i);
    for(auto j: tmp){
      primefactor[j.first] += j.second;
    }
  }
  for(auto i: primefactor){
    ans *= i.second+1;
  }
  cout << ans.val() << endl;
}