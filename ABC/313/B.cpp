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

//問題文：https://atcoder.jp/contests/abc313/tasks/abc313_b
/*
解答方針
問題文が若干難しそうですが、簡単に言うと以下のようになります。
M個の「人Xは人Yより強い」、つまり言い換えると「人Yは最強でない」という情報が与えられます。
ここで、別にXの情報は必要ありません。なぜなら、最初に全員を最強であるとし、X > Y, Y > Zという関係が成り立っているとき、
推移律によりX > Y > Zが成り立ちますが、別に弱いほうの情報を処理するだけでもYとZが最強でないということがわかり、
結果としてXが最強であるということがわかるからです。
お気持ちとしてはトポロジカルソートに近いですが、別に知らなくても簡単に解けます。
グラフ用語を使うと、「出次数が0のとき最強」ということになります。
Yに出てきたら最強フラグを取ってやり、最後に最強フラグが残っている人を出してやることで問題を解くことができます。
*/

int main(){
  int n,m;
  cin >> n >> m;
  vector<int> a(m),b(m);
  rep(i,m){
    cin >> a[i] >> b[i];
    a[i]--;
    b[i]--;
  }
  vector<int> outdeg(n,0);
  vector<vector<int>> g(n);
  rep(i,m){
    g[b[i]].push_back(a[i]);//有向辺
    outdeg[b[i]]++;
  }
  int ans = -1;
  rep(i,n){
    if(outdeg[i] == 0){
      if(ans != -1){
        cout << -1 << endl;
        return 0;
      }
      ans = i+1;
    }
  }
  cout << ans << endl;
}