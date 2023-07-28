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

//問題文：https://atcoder.jp/contests/abc308/tasks/abc308_c
/*
解答方針
浮動小数点数に関する教養問題です。
普通に浮動小数点数として計算した場合、残念ながら誤差によりWAとなる可能性があります。
よって、どうにかして整数で解く必要が出てきます。
人iと人jの成功率の大小について考えたとき、比較関数の不等式は
a_i/(a_i+b_i) > a_j/(a_j+b_j) -> a_i*(a_j+b_j) > a_j*(a_i+b_i)となります。
このとき、式変形後の両辺は2*10^18を超えないため、64bit整数であれば範囲内におさまり、オーバーフローしません。
人の比較関数を実装しておき、sortのオプションに渡しましょう。
これでこの問題を安全に解くことができます。
*/

bool comp(pair<pair<ll,ll>,ll> p, pair<pair<ll,ll>,ll> q){
  ll ai = p.first.first;
  ll bi = p.first.second;
  ll aj = q.first.first;
  ll bj = q.first.second;
  if(ai*(aj+bj) != aj*(ai+bi)){
    return ai*(aj+bj) > aj*(ai+bi);
  }else{
    return p.second < q.second;
  }
}
 
int main(){
  fast();
  int n;
  cin >> n;
  vector<int> a(n), b(n);
  rep(i,n){
    cin >> a[i] >> b[i];
  }
  vector<pair<pair<ll,ll>,ll>> ans(n);
  rep(i,n){
    ans[i] = make_pair(make_pair(a[i],b[i]),i+1);
  }
  sort(all(ans),comp);
  rep(i,n){
    cout << ans[i].second << " ";
  }
}