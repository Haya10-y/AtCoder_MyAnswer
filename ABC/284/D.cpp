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

//問題文：https://atcoder.jp/contests/abc284/tasks/abc284_d
/*
解答方針
N = p^2 * qとなるような素数p,qを探す問題。
制約上N = p^2 * qとなるような素数p,qが絶対に見つかるため、素因数分解のアルゴリズムを応用して
小さいものから試し割りしてpとqと求める。
ここで、大事なのはp,qがいつ見つかるかである。
p^2 * q = Nであり、かつpとqのうち3*10^6程度まで探索すればどちらかは見つかり、そうなるともう片方も自動的に見つかる。
そのため、ひとつの素因数が見つかった段階でプログラムを中断できる。
テストケース数はT <= 10であるため、十分間に合う。
*/

vector<pair<long long, long long> > prime_factorize(long long N) {
    vector<pair<long long, long long> > res;
    ll ex_another = 3;
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
        if(ex == 2){
          ex_another = 1;
        }
        break;
    }
 
    // 最後に残った数について
    if (N != 1) res.push_back({N, ex_another});
    return res;
}
 
int main(){
  ll t;
  cin >> t;
  rep(i,t){
    ll n;
    cin >> n;
    auto prime = prime_factorize(n);
    ll p,q;
    rep(j,sz(prime)){
      if(prime[j].second == 3){
        p = sqrt(prime[j].first);
      }else if(prime[j].second == 2){
        p = prime[j].first;
      }else{
        q = prime[j].first;
      }
    }
    cout << p << " " << q << endl;
    /*cout << endl;*/
  }
}