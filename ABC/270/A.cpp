#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i,n) for(ll i = 0; i < n; i++)
#define rep_s(i,s,n) for(ll i = s; i < n; i++)
#define rep_r(i,n) for(ll i = n-1; i >= 0; i--)
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

//問題文：https://atcoder.jp/contests/abc270/tasks/abc270_a
/*
解答方針
ありうる最終得点について考えてみましょう。
1,2,4はもちろんですが、1+2=3, 1+4=5, 2+4=6, 1+2+4=7の7通りがありえます。
このとき、最終得点だけでどの問題が解けたのか判定することができます。
もちろんif文で分岐処理をしても構いませんが、本ソースコードにない、もっと簡単な方法があります。
1 = 1 << 0, 2 = 1 << 1, 4 = 1 << 2であることから、問題が解答できたかどうかはbitごとに独立にとることができます。
この性質を使うことで、より簡単に解答することができます。
ただし、この解答にはbit全探索で使うようなテクニックが含まれているため、灰上位～茶色以降向けでしょう。
*/

int main() {
  ll a,b;
  cin >> a >> b;
  vector<bool> takahashi(3,false), aoki(3,false), snuke(3,false);
  if(a % 2 == 1){
    takahashi[0] = true;
  }
  if(b % 2 == 1){
    aoki[0] = true;
  }
  if(a / 4 == 1){
    takahashi[2] = true;
  }
  if(b / 4 == 1){
    aoki[2] = true;
  }
  takahashi[1] = (a - (4*takahashi[2]+takahashi[0]))/2;
  aoki[1] = (b - (4*aoki[2]+aoki[0]))/2;
  rep(i,3){
    snuke[i] = takahashi[i] || aoki[i];
  }
  cout << 4*snuke[2]+2*snuke[1]+snuke[0] << endl;
}