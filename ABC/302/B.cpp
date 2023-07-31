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

//問題文：https://atcoder.jp/contests/abc302/tasks/abc302_b
/*
解答方針
かなり難しい問題です。ABC258Bの類題です。
https://atcoder.jp/contests/abc258/tasks/abc258_b
各点から縦横斜めの8方向に伸ばし、5つ並んだときの並びが"snuke"であるか判定する問題です。
方向の実装はいくつかありますが（-1 <= dx <= 1, -1 <= dy <= 1で二重ループ、dx = dy = 0のときcontinue、など）
今回は配列dx,dyをあらかじめ用意して1重ループで済ませるようにしました（ネストが少なくなってすみます）。
あとはすべての点から線を伸ばし、5つ目まで伸ばすことができたら並びが"snuke"になっているか判定しましょう。
*/

int main(){
  int h,w;
  cin >> h >> w;
  vector<string> s(h);
  vector<int> dx = {1,1,0,-1,-1,-1,0,1};
  vector<int> dy = {0,1,1,1,0,-1,-1,-1};
  rep(i,h){
    cin >> s[i];
  }
  rep(i,h){
    rep(j,w){
      if(s[i][j] != 's'){
        continue;
      }
      rep(k,8){ //dydx
        if(i+dy[k]*4 < 0 || i+dy[k]*4 >= h || j+dx[k]*4 < 0 || j+dx[k]*4 >= w){
          continue;
        }
        if(s[i+dy[k]][j+dx[k]] == 'n' && s[i+dy[k]*2][j+dx[k]*2] == 'u' &&s[i+dy[k]*3][j+dx[k]*3] == 'k' &&s[i+dy[k]*4][j+dx[k]*4] == 'e'){
          rep(l,5){
            cout << i+dy[k]*l+1 << " " << j+dx[k]*l+1 << endl;
          }
        }
      }
    }
  }
}