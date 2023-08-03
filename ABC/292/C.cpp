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

//問題文：https://atcoder.jp/contests/abc292/tasks/abc292_c
/*
解答方針
AB + CD = NとなるA,B,C,Dを求めたい。
ここで大事なこととして、N <= 2*10^5であるため、ABの値およびCDの値はせいぜいN以下ということになる。
全てに対してループを回すと当然間に合わないので、ABの値を全探索して考えてみよう。A,Bの二重ループになるが、A * B <= Nという制約上間に合う。
ABの値が決まれば、AB + CD = NよりCDの値が一意に決まる。
あとはCDの約数の個数を求めればよい。なお、一度求めたらメモしておくことにより無駄な作業を減らせる。
これを足していくことにより答えを導くことができる。
計算量はO(N*sqrt(N))程度であり、ギリギリ間に合う。もっと効率のよいアルゴリズムがあるはずだ。
*/
ll divisor(long long n) {
    ll ret = 0;
    for (long long i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            ret++;
            if (i * i != n) ret++;
        }
    }
    //sort(ret.begin(), ret.end()); // 昇順に並べる
    return ret;
}
 
int main(){
  ll n;
  cin >> n;
  vector<pair<ll,ll>> ab;
  vector<ll> divmemo(n+1,-1);
  ll cnt = 0;
  rep_s(a,1,n){
    for(ll b = 1; a*b <= n; b++){
      ll cd = n-a*b;
      ll div;
      if(divmemo[cd] != -1){
        div = divmemo[cd];
      }else{
        div = divisor(cd);
        divmemo[cd] = div;
      }
      cnt += div;
    }
  }
  cout << cnt << endl;
}