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
#define mod1 998244353
#define mod2 1000000007

//問題文：https://atcoder.jp/contests/abc283/tasks/abc283_d
/*
解答方針
この問題は以下のような文章に置き換えることができます。
左から順番に処理し、英小文字の名前の変数が定義される。
現在のスコープ上に変数があったら変数名の衝突が起き、高橋くんは気を失ってしまう。

つまり、スコープ上に変数があるかどうかを判定したいです。
一番わかりやすい方法としては、どのネストに変数があるか判定するものが挙げられます。
左括弧が入ったらネストの深さを1増やし、右括弧が入ったらネストの深さを1減らすようにして記録していきます。
ネストが減ったときにそのネスト内に変数があればそれを削除するように実装しましょう。
最後まで処理が行えればYes、途中で衝突が起きたらNoです。
*/

int main(){
  string s;
  cin >> s;
  map<ll,map<char,ll>> mp_depth;
  map<char,ll> mp_count;
  ll depth = 0;
  rep(i,sz(s)){
    if(s[i] == '('){
      depth++;
    }else if(s[i] == ')'){
      for(auto j:mp_depth[depth]){
        mp_count[j.first] -= j.second;
      }
      mp_depth[depth].clear();
      depth--;
    }else{
      if(mp_count[s[i]] >= 1){
        cout << "No" << endl;
        return 0;
      }
      mp_depth[depth][s[i]]++;
      mp_count[s[i]]++;
    }
  }
  cout << "Yes" << endl;
}