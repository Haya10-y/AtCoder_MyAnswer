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
constexpr int mod1 = 998244353;
constexpr int mod2 = 1000000007;
 
//QCFium法
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
 
//問題文：https://atcoder.jp/contests/abc293/tasks/abc293_d
/*
解答方針
前提として、同じロープの左右は繋がっているものとする。
ロープを繋げるということは、グラフの頂点同士を辺で繋げるということに等しい。
閉路検出にはUnion-Findを用いる。もちろんBFSやDFSでも可能。
ロープが環状になった時点で次のロープの追加がなくなるため、そうなったときに環状ロープのカウンタを増やす。
最後に連結成分の個数を求め、そこから環状の数を引くことで環状でないロープの組の数を求めることができる。
*/

int main(){
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n,m;
  cin >> n >> m;
  int x = 0;
  vector<int> a(m), c(m);
  vector<char> b(m), d(m);
  rep(i,m){
    cin >> a[i] >> b[i] >> c[i] >> d[i];
  }
  dsu uf(n*2);
  for(int i = 0; i < n; i++){
    uf.merge(i*2,i*2+1); //赤を2i, 青を2i+1としたとき, 赤と青はつながっていることが確定する
  }
  rep(i,m){
    int u,v;
    if(b[i] == 'R'){
      u = (a[i]-1)*2;
    }else{
      u = (a[i]-1)*2+1;
    }
    if(d[i] == 'R'){
      v = (c[i]-1)*2;
    }else{
      v = (c[i]-1)*2+1;
    }
    if(uf.same(u,v)){
      x++;
    }else{
      uf.merge(u,v);
    }
  }
  auto g = uf.groups();
  int y = sz(g)-x;
  cout << x << " " << y << "\n";
}