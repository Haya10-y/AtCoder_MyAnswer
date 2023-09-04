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

//問題文：https://atcoder.jp/contests/abc215/tasks/abc215_d
/*
解答方針
すべてのA_iに対してA_iとkが互いに素であるkをすべて求める問題。
すなわち、ひとつでもA_iとkについて共通な素因数が見つかったらアウトということである。
最初はすべて条件を満たすものとし、条件を満たさなくなったらラベルを剥奪する。
つまり、すべてのA_iに対して素因数分解をし、それらの倍数についてラベルを剥奪していけばよい。
素因数分解でO(N*(sqrt(A_i))),素因数の個数は10^5までの素数の個数を考えるとたかだか10^4個程度である。
また、素数の値が大きくなっていくほど処理が早く終わるため、計算量はあまり大きくならない（この制約下では十分高速）。
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
  ll n,m;
  cin >> n >> m;
  set<ll> st;
  rep(i,n){
    ll tmp;
    cin >> tmp;
    if(tmp != 1){
      st.insert(tmp);
    }
  }
  set<ll> st_comp;
  for(auto i: st){
    vector<pair<ll,ll>> prime = prime_factorize(i);
    for(auto j: prime){
      if(j.first != 1){
        st_comp.insert(j.first);
      }
    }
  }
  vector<bool> isOK(m+1,true);
  isOK[0] = false;
  for(auto i: st_comp){
    ll ng = i;
    while(ng <= m){
      isOK[ng] = false;
      ng += i;
    }
  }
  set<ll> ans;
  rep(i,m+1){
    if(isOK[i]){
      ans.insert(i);
    }
  }
  cout << sz(ans) << endl;
  for(auto i: ans){
    cout << i << endl;
  }
}