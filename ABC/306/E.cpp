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
 
//問題文：https://atcoder.jp/contests/abc306/tasks/abc306_e
/*
解答方針
multisetをふたつ用意し、上位K個とそれ以外に振り分ける。
更新時にはO(logN)でmultisetの中身を探索し、見つけたら値を変更する。
その後、上位multisetの最後と下位multisetの最初を比較し、必要に応じて入れ替える。ここはたかだかO(logN)で済む。
なお、処理の都合上ダミーデータとして上位、下位のmultisetにそれぞれ0を挿入している。制約上K<=Nであることから、この0は必ず下位のmultisetに配置される。
計算量はO(QlogN)程度になる。
*/

int main(){
  fast();
  int n,k,q;
  cin >> n >> k >> q;
  vector<int> a(n,0);
  //降順ソート、greaterで上位k個までをとる
  //setをふたつ使う？
  multiset<int,greater<int>> upperk;
  multiset<int,greater<int>> lower;
  ll ans = 0;
  rep(i,k){
    upperk.insert(0);
  }
  rep(i,n-k){
    lower.insert(0);
  }
  rep(i,q){
    int x,y;
    cin >> x >> y;
    x--;
    int a_prev = a[x];
    a[x] = y;
    //更新処理
    //まず元あるやつを削除して新しいのを入れる
    if(upperk.count(a_prev)){
      upperk.erase(upperk.find(a_prev));
      upperk.insert(a[x]);
      ans -= a_prev;
      ans += a[x];
    }else{
      lower.erase(lower.find(a_prev));
      lower.insert(a[x]);
    }
    //次に移動の処理、lowerからひとつとってupperと交換
    if(*prev(upperk.end()) < *lower.begin()){
      int tolower = *prev(upperk.end());
      int toupper = *lower.begin();
      int diff = toupper - tolower;
      ans += diff;
      upperk.erase(prev(upperk.end()));
      lower.erase(lower.begin());
      upperk.insert(toupper);
      lower.insert(tolower);
    }
    cout << ans << endl;
  }
}