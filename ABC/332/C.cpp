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
与えられた4条件について考える．
食事の日は無地またはロゴ入りTシャツを使うことになっているが，競プロイベントのときにはロゴ入りTシャツを使わなければならない．
このことから，無地のTシャツを使えるときは食事のときしかないため，食事の日には無地Tシャツを優先的に使おう．
また，予定のない日にはTシャツを選択して在庫を回復させられる．
無地およびロゴ入りTシャツの最大値と現在値をもったうえでシミュレーションしていこう．
予定のないときは現在値を最大値とし，食事の日は無地を優先的に使い，無地がなければロゴ入りを使う．
競プロイベントの日はロゴ入りを絶対に使う．
ここでロゴ入りTシャツの在庫がない状態で使う必要が出てきたときに，ロゴ入りTシャツを1つ買う．このとき最大値が1増え，現在値は0のままである．
最後に求めたいものはロゴ入りTシャツの最大値である．
*/

int main(){
  int n,m;
  cin >> n >> m;
  string s;
  cin >> s;
  int ans = 0;
  int rest = m;
  int logo = 0;
  rep(i,n){
    if(s[i] == '0'){
      rest = m;
      logo = ans;
    }else if(s[i] == '1'){
      if(rest > 0){
        rest--;
      }else if(logo > 0){
        logo--;
      }else{
        ans++;
      }
    }else{
      if(logo == 0){
        ans++;
      }else{
        logo--;
      }
    }
  }
  cout << ans << endl;
}