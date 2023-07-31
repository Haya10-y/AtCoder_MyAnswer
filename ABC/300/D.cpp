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

//問題文：https://atcoder.jp/contests/abc300/tasks/abc300_d
/*
解答方針
a,b,cの3変数を扱う問題。
素数の列挙はエラトステネスの篩とよばれるアルゴリズムでO(NloglogN)で行うことができる。
ただし、計算量的に10^12までの素数を列挙することはできない。そのため、どこまで列挙すべきか考える。
ここで、少なくともc^2 < a^2*b*c^2 <= Nとなり、cは高々sqrt(N)以下である。
そのため、sqrt(N)までの素数を列挙して進めることにした。実際、これでACをとることができる。
10^6までの素数は78498 < 8*10^4個である。abcの3重ループをすると間に合わないように見えるが、
実際は早い段階でbreakが行われるため、ループ数はあまりかからない。
探索時にはa < b < cであることを使い、ループ数をうまく減らしたい。
*/

// 1 以上 N 以下の整数が素数かどうかを返す
vector<bool> Eratosthenes(int N) {
    // テーブル
    vector<bool> isprime(N+1, true);
 
    // 0, 1 は予めふるい落としておく
    isprime[0] = isprime[1] = false;
 
    // ふるい
    for (int p = 2; p <= N; ++p) {
        // すでに合成数であるものはスキップする
        if (!isprime[p]) continue;
 
        // p 以外の p の倍数から素数ラベルを剥奪
        for (int q = p * 2; q <= N; q += p) {
            isprime[q] = false;
        }
    }
 
    // 1 以上 N 以下の整数が素数かどうか
    return isprime;
}
 
int main(){
  ll n;
  cin >> n;
  
  int sqrtn = sqrt(n)+1;
  auto isprime = Eratosthenes(sqrtn);
  vector<ll> prime; //のちにllでの計算が必要になるため
  rep(i,sqrtn+1){
    if(isprime[i]){
      prime.push_back(i);
    }
  }
  //cout << sz(prime) << endl; //最大10^5程度、二重ループすら厳しい
  int ans = 0;
  rep(i,sz(prime)){
    if(prime[i]*prime[i]*prime[i+1]*prime[i+2]*prime[i+2] > n){
      break;
    }
    rep_s(j,i+1,sz(prime)){
      if(prime[i]*prime[i]*prime[j]*prime[j+1]*prime[j+1] > n){
        break;
      }
      rep_s(k,j+1,sz(prime)){
        if(prime[i]*prime[i]*prime[j]*prime[k]*prime[k] > n){
          break;
        }
        ans++;
      }
    }
  }
  cout << ans << endl;
}