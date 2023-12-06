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

/*
解答方針
同じサイズのスライムを2匹選んで消費し、2倍のサイズのスライムを1匹つくる問題。
消費のフェーズにおいてはまとめて処理することが可能であるため、mapなどを使ってサイズが小さい順からまとめて消費→生産を繰り返していけば解ける。
ただし、愚直で遅い解法であるためTLEには注意すること。定数倍が悪くなければACを獲得できる。
*/

int main(){
  fast();
  int n;
  cin >> n;
  map<ll,ll> mp;
  ll s,c;
  rep(i,n){
    cin >> s >> c;
    mp[s] += c;
  }
  ll siz, num;
  for(auto i: mp){
    siz = i.first;
    num = i.second;
    if(num >= 2){
      mp[siz*2] += num/2;
    }
    mp[siz] %= 2;
  }
  ll ans = 0;
  for(auto i: mp){
    ans += i.second;
  }
  cout << ans << endl;
}