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
#define mod1 998244353
#define mod2 1000000007

//問題文：https://atcoder.jp/contests/abc280/tasks/abc280_d
/*
解答方針
N!をそのまま計算すると大変です。そのため、素因数分解して考えましょう。
Kの素因数分解後の数がすべてN!の中に入ったときの最初のNが答えになります。
そのため、まずKを素因数分解します。ここで、Kの素因数のうち最大のものをPとおいたとき、N >= Pとなります。
これは、N!の素因数にPが含まれるのはN = Pのときが最初であるためです。
そのため、P >= 10^6であればN = Pであることが確定し、これ以上計算する必要はなくなります。よってこの場合はPを出力します。
以下はP < 10^6のときについてです。
N!の素因数分解は1からNまでの数字を素因数分解してかけあわせましょう。計算量はO(N*sqrt(N))で、N <= 10^6ですがなんとか間に合います。
素因数分解して指数を足していき、Kの素因数の指数以上になればそれが答えです。
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
  ll k;
  cin >> k;
  vector<pair<ll,ll>> prime_k = prime_factorize(k);
  /*rep(i,sz(prime_k)){
    cout << prime_k[i].first << " " << prime_k[i].second << endl;
  }*/
  map<ll,ll> mp_k(all(prime_k));
  map<ll,ll> mp_n;
  ll i = 1;
  ll calc_max = -INFINITY;
  for(auto j: prime_k){
    ll calc = ((ceil(sqrt(8*j.second+1))-1)*j.first)/2;
    calc_max = max(calc,calc_max);
  }
  //cout << "prime end" << endl;
  if(calc_max >= 1000000){
    cout << calc_max <<endl;
    return 0;
  }
  while(true){
    bool flag = false;
    vector<pair<ll,ll>> tmp = prime_factorize(i);
    rep(j,sz(tmp)){
      mp_n[tmp[j].first] += tmp[j].second;
    }
    i++;
    for(auto j: mp_k){
      if(mp_n[j.first] < j.second){
        flag = true;
        break;
      }
    }
    if(flag){
      continue;
    }
    cout << i-1 << endl;
    return 0;
  }
  /*for(auto i: mp_k){
    cout << i.first << " " << i.second << endl;
  }*/
}