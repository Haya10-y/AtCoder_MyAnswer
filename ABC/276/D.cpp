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

//問題文：https://atcoder.jp/contests/abc276/tasks/abc276_d
/*
解答方針
a_1 = a_2 = ... = a_Nを満たすときはどういうときなのか考えてみましょう。
これはつまり、a_i = 2^x * 3^y * zとなり、すべてのa_iに対してzが共通であるとき条件を満たします。
ただし、a_1 = a_2 = ... = a_N = 6 = 2^1 * 3^1になるような場合でも問題ないため、2で割った回数および3で割った回数の最小値を
求めておく必要があることに注意しておきましょう。
1回割るごとにカウントし、2で割った回数および3で割った回数の最小値それぞれにNをかけたものを引いてやりましょう。
この解答では素因数分解のアルゴリズムを改造していますが、普通に割っても問題ありません。
計算量はO(Nlog(max(a_i)))程度になりそうです。
*/

vector<pair<long long, long long> > prime_factorize(long long N) {
    vector<pair<long long, long long> > res;
    for (long long a = 2; a <= 3; ++a) {
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
  ll mn = *min_element(all(a));
  auto mnitr = min_element(all(a));
  ll mnidx = distance(a.begin(), mnitr);
  vector<vector<pair<ll,ll>>> prime(n);
  rep(i,n){
    prime[i] = prime_factorize(a[i]);
  }
  ll mn_remain = 1;
  rep(i,sz(prime[mnidx])){
    if(prime[mnidx][i].first != 2 && prime[mnidx][i].first != 3){
      mn_remain = prime[mnidx][i].first;
    }
  }
  //cout << mn_remain << endl;
  rep(i,n){
    rep(j,sz(prime[i])){
      //cerr << prime[i][j].first << " " << prime[i][j].second << " , ";
      if(prime[i][j].first != 2 && prime[i][j].first != 3){
        if(prime[i][j].first != mn_remain){
          cout << -1 << endl;
          return 0;
        }
      }
    }
    //cerr << endl;
  }
  
  //ここまで無理な場合、ここからいける場合
  /*ll count_2 = 0;
  ll count_3 = 0;
  rep(i,sz(prime[mnidx])){
    if(prime[mnidx][i].first == 2){
      count_2 = prime[mnidx][i].second;
    }else if(prime[mnidx][i].first == 3){
      count_3 = prime[mnidx][i].second;
    }
  }*/
  vector<ll> count_2_all(n,0);
  vector<ll> count_3_all(n,0);
  rep(i,n){
    rep(j,sz(prime[i])){
      if(prime[i][j].first == 2){
      	count_2_all[i] = prime[i][j].second;
      }else if(prime[i][j].first == 3){
        count_3_all[i] = prime[i][j].second;
      }
    }
  }
  /*rep(i,n){
    //cout << a[i] << " " <<count_2_all[i] << " " << count_3_all[i] << endl;
  }*/
  ll vec2_min = *min_element(all(count_2_all));
  ll vec3_min = *min_element(all(count_3_all));
  ll sum_2 = 0;
  ll sum_3 = 0;
  rep(i,n){
    rep(j,sz(prime[i])){
      if(prime[i][j].first == 2){
        sum_2 += prime[i][j].second;
      }else if(prime[i][j].first == 3){
        sum_3 += prime[i][j].second;
      }
    }
  }
  cout << sum_2+sum_3-vec2_min*n-vec3_min*n << endl;
}