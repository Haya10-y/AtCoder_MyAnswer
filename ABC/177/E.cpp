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

//問題文：https://atcoder.jp/contests/abc177/tasks/abc177_e
/*
解答方針
まずpairwise coprimeについて考える。数列中のすべての要素について
互いに素であるときpairwise coprimeといえる。
これはすべての要素について素因数分解をしたあとに、素因数のリストに入れていき、すでに要素があったら
pairwise coprimeでない、とすればよい。
10^6までの素数はたかだか78498 < 10^5個であり、また素数階乗 (Primorial) 2*3*5*7*11*13*17*19 = 9699690 > 10^6より、
素因数の最大個数はたかだか7個でおさまるため、余裕で間に合う。
setwise coprimeの判定は非常に簡単で、左から順番にGCDを求めていけばよい。
最後にGCDが1ならsetwise coprimeである。
*/

vector<pair<long long, long long> > prime_factorize(long long N) {
    vector<pair<long long, long long> > res;
    for (long long a = 2; a * a <= N; ++a) {
        if (N % a != 0) continue;
        long long ex = 0; // 指数

        // 割れる限り割り続ける
        while (N % a == 0) {
            ++ex;
            N /= a;
        }

        // その結果を push
        res.push_back({a, ex});
    }

    // 最後に残った数について
    if (N != 1) res.push_back({N, 1});
    return res;
}

int main(){
  ll n;
  cin >> n;
  vector<ll> a(n);
  rep(i,n){
    cin >> a[i];
  }
  set<ll> prime;
  bool pairwise = true;
  bool setwise = true;
  rep(i,n){
    vector<pair<ll,ll>> p = prime_factorize(a[i]);
    for(auto j:p){
      if(!prime.count(j.first)){
        prime.insert(j.first);
      }else{
        pairwise = false;
        break;
      }
    }
    if(!pairwise){
      break;
    }
  }
  ll gcd_all = a[0];
  rep_s(i,1,n){
    gcd_all = __gcd(gcd_all,a[i]);
  }
  if(gcd_all != 1){
    setwise = false;
  }
  if(pairwise){
    cout << "pairwise coprime" << endl;
  }else if(setwise){
    cout << "setwise coprime" << endl;
  }else{
    cout << "not coprime" << endl;
  }
}