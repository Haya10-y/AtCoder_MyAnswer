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

//問題文：https://atcoder.jp/contests/abc302/tasks/abc302_e
/*
解答方針
一見難しそうだが、実は愚直で解ける。
グラフをvector<set>でもっておき、頂点uに対するvを高速で見つけられるようにする。
頂点uとvを結ぶ辺の追加は簡単だが、問題なのは頂点vを結ぶ辺の全削除である。
しかし、これはvに繋がっているすべての辺uに対して、uとvのつながりを切ればよいだけである。計算量は高く見積もっても対数時間である。
最後にvのsetを空にしてやれば処理が完了する。
この処理中に頂点ごとの次数を記録していけば、どれだけの点が孤立しているかがわかる。
いちいちすべての頂点に対して孤立しているか判定していると間に合わないため、孤立点の数をもつ変数をつかって記録するようにしよう。
*/

int main(){
  fast();
  int n,q;
  cin >> n >> q;
  vector<int> deg(n,0); //次数、最初は0
  int ans = n; //非連結であるノード数、最初はn
  vector<set<int>> g(n);
  rep(i,q){
    int num;
    cin >> num;
    if(num == 1){
      int u,v;
      cin >> u >> v;
      u--;v--;
      if(deg[u] == 0){ //uが非連結の場合
        ans--;
      }
      if(deg[v] == 0){ //vが非連結の場合
        ans--;
      }
      deg[u]++; //制約よりこれは常に正しい…はず？
      deg[v]++;
      g[u].insert(v); //setにinsert
      g[v].insert(u);
    }else{
      int v;
      cin >> v;
      v--;
      for(auto j: g[v]){ //vに繋がっているすべての辺について
        g[j].erase(v); //jとvのつながりを切る
        if(deg[j] == 1){ //次数が1 -> 0になる場合
          ans++; //連結 -> 非連結
        }
        deg[j]--; //次数を減らす
      }
      if(deg[v] != 0){ //vが連結であった場合に限り
        ans++; //連結 -> 非連結
      }
      deg[v] = 0; //次数を0にする
      g[v].clear(); //setのクリア
    }
    cout << ans << endl;
  }
  
}