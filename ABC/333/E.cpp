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
#define pii pair<int,int>

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
DPだと難しそうなので，1順させるだけで特定できる方法を考える．
取得したポーションは使うまで残ってしまうため，ポーションは後でとったほうがより所持ポーションの最大値が小さくなる．
そのため，後ろから考えてみる．
各タイプとその合計に関して，残り必要ポーション数について考える．
t = 2のときはポーションが必要になるため，必要ポーション数をひとつ足す．
t = 1のときはポーションを拾うことを考えるが，ここでタイプごとの必要ポーション数が0なら拾わず，1以上なら拾う．
これを後ろから前に持っていき，最後に合計必要ポーション数が0なら条件を達成しており，1以上なら未達成である．
最大所持ポーション数は最大必要ポーション数と等価であるため，イベントごとに最大必要ポーション数を更新すればよい．
公式解説ではimos法を使っているが，それすら必要ないのでたぶん楽な解法．
*/

int main(){
  int n;
  cin >> n;
  vector<int> t(n),x(n);
  rep(i,n){
    cin >> t[i] >> x[i];
    x[i]--;
  }
  vector<int> vans;
  int ans = 0;
  vector<int> maxneeded_all(n,0);
  vector<int> nowneeded_all(n,0);
  int nowneeded = 0;
  rep_r(i,n){
    if(t[i] == 1){
      if(nowneeded_all[x[i]] == 0){
        vans.push_back(0);
      }else{
        nowneeded_all[x[i]]--;
        nowneeded--;
        vans.push_back(1);
      }
    }else{
      nowneeded_all[x[i]]++;
      nowneeded++;
      maxneeded_all[x[i]] = max(maxneeded_all[x[i]], nowneeded_all[x[i]]);
      ans = max(ans, nowneeded);
    }
  }
  if(nowneeded >= 1){
    cout << -1 << endl;
    return 0;
  }
  cout << ans << endl;
  rep_r(i,sz(vans)){
    cout << vans[i] << " ";
  }
  cout << endl;
}