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
一見難しそうだが、Sの合計の文字数が5*10^5以下であることから、普通にやるだけで解くことができる。
ここで注目すべきは、T'とSの文字数である。
文字数の差が2以上の場合はどうあがいても候補に入り得ないため、この時点でスルーする。
あとは文字数の差が0について、1についてそれぞれ考える。
差が0のときはT'[i]とS[i]をひとつずつ比べ、異なっている場所が1箇所以下であったときは条件に合致する。
差が1のときはT'[i]とS[i]をひとつずつ比べ、一度異なっていたら文字数が大きい方のみ1個ずらし、再度確認していく。
裏技としてC++のbool型はfalseが0、trueが1であるため、これを直接インデックスに足すことで楽に処理できる。
最後まで処理できたら条件に合致しており、途中で処理を中断した場合は条件に合致していないことになる。
あとは条件に合致した文字列の個数とその番号を出力すればよい。
*/

int main(){
  fast();
  int n;
  string tp;
  cin >> n >> tp;
  string s;
  int ans = 0;
  vector<int> v;
  int cnt;
  rep(i,n){
    cin >> s;
    if(sz(s) == sz(tp)){
      //条件1,4を判定
      cnt = 0;
      rep(j,sz(s)){
        if(s[j] != tp[j]){
          cnt++;
        }
      }
      if(cnt <= 1){
        v.push_back(i+1);
        ans++;
      }
    }else if(sz(s)+1 == sz(tp)){
      //条件2を判定
      bool skipped = false;
      rep(j,sz(s)){
        if(s[j] != tp[j+skipped]){
          if(skipped){
            break;
          }
          skipped = true;
          j--;
        }
        if(j == sz(s)-1){
          v.push_back(i+1);
          ans++;
        }
      }
    }else if(sz(s) == sz(tp)+1){
      //条件3を判定
      bool skipped = false;
      rep(j,sz(tp)){
        if(s[j+skipped] != tp[j]){
          if(skipped){
            break;
          }
          skipped = true;
          j--;
        }
        if(j == sz(tp)-1){
          v.push_back(i+1);
          ans++;
        }
      }
    }
  }
  cout << ans << endl;
  rep(i,ans){
    cout << v[i] << " ";
  }
  cout << endl;
}