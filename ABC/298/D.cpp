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

//問題文：https://atcoder.jp/contests/abc298/tasks/abc298_d
/*
解答方針
末尾に追加して先頭から消すので、queueをつかいそう。
また、桁数ごとに998244353で割ったあまりを求めておくと早そう。
桁数は別の変数で管理して、追加するときと消すときに処理してやると楽。
要素追加時には10倍して追加するものを足し、要素削除時には削除要素*10^桁数 % 998244353を引く。
前処理で10^桁数 % 998244353は定義済みであるため、ここはO(1)で処理できる。
桁数は最大Q桁であるため、前処理にO(Q)、クエリの処理にO(Q)かかり、合計の計算量はO(Q)である。
*/

int main(){
  fast();
  int q;
  cin >> q;
  vector<mint> m(q+1);
  queue<int> s;
  s.push(1);
  //mod 998244353で出す、sは9e18を超える可能性がある
  //n*10^m mod 998244353を出せれば勝ちだが… めんどいけど1 <= m <= 6*10^5において剰余をまとめる？
  m[0] = 1; //10かけてmod998244353するので、初期値1だと都合がいい
  rep_s(i,1,q+1){ //O(Q)なので余裕
    m[i] = m[i-1]*10;
    //cout << m[i].val() << endl;
  }
  mint ans = 1;
  int digit = 0; //先頭の桁が10^digitの桁
  rep(i,q){
    int num;
    cin >> num;
    
    if(num == 1){
      int x;
      cin >> x;
      s.push(x);
      digit++;
      ans *= 10; //1桁上がるため10倍する
      ans += x;
    }else if(num == 2){
      int x = s.front();
      s.pop();
      mint sub = m[digit];
      sub *= x; //(x * 10^digit)%mod1
      ans -= sub; //ans < subでもmodintがたぶんなんとかしてくれる
      digit--;
    }else{
      cout << ans.val() << endl;
    }
  }
}