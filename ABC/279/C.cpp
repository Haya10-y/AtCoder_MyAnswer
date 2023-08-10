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

//問題文：https://atcoder.jp/contests/abc279/tasks/abc279_c
/*
解答方針
IIDXをやっている人なら馴染み深い問題かもしれません。以降はわかりやすいよう、音ゲー用語に置き換えて解説します。
要するに、譜面Tが譜面SのRANDOM譜面として選ばれる可能性があるかというものです。
方法としては、レーンごとにどこにノーツがあるかということを考え、ノーツがある番号を記録していけばよいです。
あとはそこからソートをしましょう。
TがSの乱ならソート後の譜面は同一になるため、このようになるかどうかを判定すればよいです。
なお、入力例4ではデニムの大外れである2356配置を崩して2Pガチ割れ大当たりを引いています。やったね！
*/

int main(){
  ll h,w;
  cin >> h >> w;
  vector<string> s(h);
  rep(i,h){
    cin >> s[i];
  }
  vector<string> t(h);
  rep(i,h){
    cin >> t[i];
  }
  vector<vector<ll>> num_s(w,vector<ll>());
  vector<vector<ll>> num_t(w,vector<ll>());
  rep(i,w){
    rep(j,h){
      if(s[j][i] == '#'){
        num_s[i].push_back(j);
      }
      if(t[j][i] == '#'){
        num_t[i].push_back(j);
      }
    }
  }
  sort(all(num_s));
  sort(all(num_t));
  if(num_s == num_t){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }
}