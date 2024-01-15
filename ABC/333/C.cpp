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

long long pow_ll(long long x, long long n) {
    long long ret = 1;
    while (n > 0) {
        if (n & 1) ret *= x;  // n の最下位bitが 1 ならば x^(2^i) をかける
        x *= x;
        n >>= 1;  // n を1bit 左にずらす
    }
    return ret;
}

/*
解答方針
333番目の解は112222222233である．このため，制約より10^13までのレピュニットを考えれば十分である．
レピュニットの数が13個程度であるため，3つのレピュニットの和を全列挙しても13^3 = 2197個であるため十分間に合う．
順番を考える際は重複を考えないかつ順序付きだと楽なので，順序付き集合setをつかうとよい．
*/

int main(){
  int n;
  cin >> n;
  vector<ll> reps;
  ll tmp = 0;
  rep(i,19){
    tmp += pow_ll(10,i);
    reps.push_back(tmp);
  }
  set<ll> repsum;
  for(auto i: reps){
    for(auto j: reps){
      for(auto k: reps){
        repsum.insert(i+j+k);
      }
    }
  }
  int idx = 1;
  for(auto i: repsum){
    if(idx == n){
      cout << i << endl;
      return 0;
    }
    idx++;
  }
}