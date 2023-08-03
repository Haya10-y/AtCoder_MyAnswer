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
const int mod1 = 998244353;
const int mod2 = 1000000007;
 
//QCFium法
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
 
void fast(){
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
}
 
#define endl "\n" //flushのとき外す

//問題文：https://atcoder.jp/contests/abc294/tasks/abc294_e
/*
解答方針
ランレングス圧縮後のサイズが最大10^12で、一見愚直だと厳しそうに感じる。
しかし、圧縮前のサイズは最大10^5であり、かつ同じものが繋がっていることが多いことから、
数字が切り替わるタイミングで処理を変え、それまではまとめて同じ処理をする、という方針でやると
O(N_1 + N_2)で解くことができる。
少しややこしい実装になるが、がんばってみよう。
行1と行2のいま見ているところのうち、どちらが残りの数が少ないかということを見て
大きい方から小さい方の数を引き、小さい方は次の要素にうつす、という実装をしている。
特殊なアルゴリズムは全く使わないため、実装力のみが求められる。
*/

int main(){
  fast();
  ll l,n1,n2;
  cin >> l >> n1 >> n2;
  vector<ll> v1(n1), l1(n1), v2(n2), l2(n2);
  rep(i,n1){
    cin >> v1[i] >> l1[i];
  }
  rep(i,n2){
    cin >> v2[i] >> l2[i];
  }
  vector<ll> sum1(n1+1), sum2(n2+1); //なんとなく累積和
  sum1[0] = 0;
  sum2[0] = 0;
  rep(i,n1){
    sum1[i+1] = sum1[i]+l1[i];
  }
  rep(i,n2){
    sum2[i+1] = sum2[i]+l2[i];
  }
  ll ans = 0;
  ll now = min(l1[0],l2[0]);
  if(v1[0] == v2[0]){
    ans += min(l1[0],l2[0]);
  }
  ll idxv1 = 0;
  ll idxv2 = 0;
  if(l1[0] < l2[0]){
    idxv1++;
  }else if(l1[0] > l2[0]){
    idxv2++;
  }else{
    idxv1++;
    idxv2++;
  }
  //どちらかはsum[idxvx]になっているはず
  while(idxv1 < n1 && idxv2 < n2){
    ll rest_v1 = sum1[idxv1+1]-now;
    ll rest_v2 = sum2[idxv2+1]-now;
    ll nextstep = min(rest_v1, rest_v2);
    if(v1[idxv1] == v2[idxv2]){
      ans += nextstep;
    }
    bool flag = false;
    if(rest_v1 < rest_v2){
      idxv1++;
    }else if(rest_v1 > rest_v2){
      idxv2++;
    }else{
      idxv1++;
      idxv2++;
    }
    now += nextstep;
    
  }
  cout << ans << endl;
}