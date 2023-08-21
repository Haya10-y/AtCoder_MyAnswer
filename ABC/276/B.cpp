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

//問題文：https://atcoder.jp/contests/abc276/tasks/abc276_b
/*
解答方針
グラフ問題で必要な、隣接リストをつくる問題です。
ひとつずつ順番にやっていきましょう。
配列の中身を空の配列にした二次元配列をつくり、そこに頂点iと繋がっている頂点の番号を入れていきます。
すべての頂点を繋げたら、昇順での出力が必須であるため各配列を昇順ソートします。
あとは出力形式通りに出力しましょう。
茶色以降では必須のデータ構造であるため、絶対に覚えておきましょう。
*/

int main(){
  int n,m;
  cin >> n >> m;
  vector<vector<ll>> lst(n+1);
  rep(i,m){
    ll a,b;
    cin >> a >> b;
    lst[a].push_back(b);
    lst[b].push_back(a);
  }
  rep(i,sz(lst)){
    sort(all(lst[i]));
  }
  rep_s(i,1,n+1){
    cout << sz(lst[i]) << " ";
    rep(j,sz(lst[i])){
      cout << lst[i][j] << " ";
    }
    cout << endl;
  }
}