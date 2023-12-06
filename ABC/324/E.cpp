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
2つの文字列を結合する際、必ずTのprefixとなるものとTのsuffixとなるものが出てくる。
S_iとS_jを連結する際、S_iの後ろがTのprefixとなり、S_jの後ろがTのsuffixとなる。
prefixが何文字あるか、suffixが何文字あるかそれぞれの文字列について見た上で解いていけばよい。
prefixの文字列長iで全探索すると、suffixの文字列長は|T|-i以上となる。ここの区間のパターン数を求めたい。
区間和を求める際は累積和が便利であるため、suffixの文字列に対して累積和を行うことでクエリごとにO(1)でパターン数を求められる。
prefixの文字列長iのパターン数と、iに対するsuffixのパターン数をかけたものの1 <= i <= |T|における足し合わせが最後の答えとなる。
*/

int main(){
  fast();
  int n;
  string t;
  cin >> n >> t;
  vector<string> s(n);
  rep(i,n){
    cin >> s[i];
  }
  //prefix, suffixを探す
  vector<ll> prefix(sz(t)+1,0), suffix(sz(t)+1,0);
  //二重ループだが制約より大丈夫なはず
  int idx;
  rep(i,n){
    //prefixを探す、左から
    idx = 0;
    rep(j,sz(s[i])){
      if(s[i][j] == t[idx]){
        idx++;
      }
      if(idx == sz(t)){
        break;
      }
    }
    prefix[idx]++;
    //suffixを探す、右から
    idx = sz(t)-1;
    rep_r(j,sz(s[i])){
      if(s[i][j] == t[idx]){
        idx--;
      }
      if(idx == -1){
        break;
      }
    }
    //cout << sz(t)-(idx+1) << endl;
    suffix[sz(t)-(idx+1)]++;
  }
  ll ans = 0;
  vector<ll> suffix_sum(sz(t)+2, 0);
  rep(i,sz(t)+1){
    suffix_sum[i+1] = suffix_sum[i] + suffix[i]; //累積和
  }
  
  /*rep(i,sz(t)+1){
    cout << prefix[i] << " ";
  }
  cout << endl;
  
  rep(i,sz(t)+1){
    cout << suffix[i] << " ";
  }
  cout << endl;*/
  /*
  2*4+4*(1+4)+4*(5+1+4)=68.
  */
  rep(i,sz(t)+1){
    ans += prefix[i]*(suffix_sum[sz(t)+1]-suffix_sum[sz(t)-i]);
  }
  cout << ans << endl;
}