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

//問題文：https://atcoder.jp/contests/abc271/tasks/abc271_d
/*
解答方針
1つのカードにつき、上に向ける面は表と裏の2種類を選ぶことができる。
すべてのパターンを試そうとすると2^N回かかることになり、これでは到底間に合わない。
総和がちょうどSになるようなものを考えるとき、ナップザックDPや部分和DPのような考え方ができる。
すなわち、dp[i][j] -> i枚目に和がjであるような組み合わせが存在するか、と考えることができる。
これで和がSになるかどうかは判定できるが、そのあとに経路の復元が必要である。
これはあまり難しくなく、DPテーブルを後ろから順番にたどっていけばよい。2つとも選べる場合はどちらを選んでもよい。
*/

int main(){
  ll n,s;
  cin >> n >> s;
  vector<ll> a(n),b(n);
  //部分和問題に帰着
  vector<vector<bool>> dp(n+1,vector<bool>(s+1,false));
  rep(i,n){
    cin >> a[i] >> b[i];
  }
  dp[0][0] = true;
  rep(i,n){
    rep(j,s+1){
      if(dp[i][j] == true){
        if(j+a[i] <= s){
          dp[i+1][j+a[i]] = true;
        }
        if(j+b[i] <= s){
          dp[i+1][j+b[i]] = true;
        }
      }
    }
  }
  if(dp[n][s]){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
    return 0;
  }
  
  /*rep(i,n+1){
    rep(j,s+1){
      cout << dp[i][j];
    }
    cout << endl;
  }*/
  
  //経路復元
  string ans = "";
  ll s_tmp = s;
  rep_r(i,n){
    //cout << n-i-1 << " " << s_tmp-a[i] << endl;
    if(s_tmp-a[i] >= 0 && dp[i][s_tmp-a[i]]){
      ans.push_back('H');
      s_tmp -= a[i];
    }else if(s_tmp-b[i] >= 0 && dp[i][s_tmp-b[i]]){
      ans.push_back('T');
      s_tmp -= b[i];
    }
  }
  reverse(all(ans));
  cout << ans << endl;
}