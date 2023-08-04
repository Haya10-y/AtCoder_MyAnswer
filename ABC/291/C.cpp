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

//問題文：https://atcoder.jp/contests/abc291/tasks/abc291_c
/*
解答方針
LRUDの4方向への移動指示が出るので、その道中同じ座標にいたことがあるか判定する問題です。
座標をvectorでもつと要素数としてありえる数が大きすぎるため、map<pair<int,int>,bool>または
set<pair<int,int>>としてもつとより要素の数が少なくすみます。
あとは移動と記録を繰り返し、要素が被っていたらその時点でYesを返します。
最後まで被らなかったらNoを返します。
*/

int main(){
  ll n;
  cin >> n;
  string s;
  cin >> s;
  map<pair<ll,ll>, bool> mp;
  ll x = 0;
  ll y = 0;
  mp[make_pair(x,y)] = true;
  rep(i,n){
    if(s[i] == 'R'){
      x++;
    }else if(s[i] == 'L'){
      x--;
    }else if(s[i] == 'U'){
      y++;
    }else{
      y--;
    }
    if(mp[make_pair(x,y)] != true){
      mp[make_pair(x,y)] = true;
    }else{
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
}