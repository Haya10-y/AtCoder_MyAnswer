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
ドミノの塗り分け方を考える。
縦→縦の場合、横→横の場合、縦→横の場合、横→縦の場合の4通りについて考える。
縦→縦の場合は2通り、横→横の場合は3通り、縦→横の場合は2通り、横→縦の場合は1通りとなる。
あとは文字列からそれぞれのパターンを認識し、順番にかけあわせていく。
1e9+7で割ったあまりを求めることを忘れないように。不安ならmodintを使おう。
また、初手でドミノの縦横を判定する場合はN = 1のコーナーケースに気をつけること。
*/

int main(){
  int n;
  cin >> n;
  vector<string> s(2);
  cin >> s[0];
  cin >> s[1];
  if(n == 1){ //縦1個のコーナーケース
    cout << 3 << endl;
    return 0;
  }
  bool isvertical;
  mint2 ans;
  //縦縦、横横、縦横、横縦で場合分け
  
  int idx;
  //初期、縦か横か
  if(s[0][0] != s[0][1]){
    isvertical = true;
    ans = 3;
    idx = 1;
  }else{
    isvertical = false;
    ans = 6;
    idx = 2;
  }
  while(idx < n){
    if(s[0][idx] != s[0][idx+1]){ //縦
      if(isvertical){
        ans*=2;
      }
      //横は省略(ans*=1)
      isvertical = true;
      idx++;
    }else{ //横
      if(isvertical){ //縦横
        ans*=2;
      }else{ //横横
        ans*=3;
      }
      isvertical = false;
      idx+=2;
    }
  }
  cout << ans.val() << endl;
  
}