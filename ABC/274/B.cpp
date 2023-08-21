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

//問題文：https://atcoder.jp/contests/abc274/tasks/abc274_b
/*
解答方針
それぞれの列に対して、何個箱があるか、要するに何個'#'があるかという問題です。
単純に縦方向にループを回し、各列に対してカウントするだけでよいです。
縦方向のループのときは0 <= i < wかつ0 <= j < hであり、配列Cの添字がC[j][i]であることに注意しましょう。
*/

int main(){
  ll h,w;
  cin >> h >> w;
  vector<vector<char>> c(h,vector<char>(w));
  rep(i,h){
    rep(j,w){
      cin >> c[i][j];
    }
  }
  rep(i,w){
    ll count = 0;
    rep(j,h){
      if(c[j][i] == '#'){
        count++;
      }
    }
    cout << count << " ";
  }
}