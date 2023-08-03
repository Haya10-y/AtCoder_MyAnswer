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
const int mod1 = 998244353;
const int mod2 = 1000000007;
 
//QCFium法
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
 
void fast(){
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
}
 
#define endl "\n" //flushのとき外す

//問題文：https://atcoder.jp/contests/abc294/tasks/abc294_c
/*
解答方針
AとBをつなげてソートした配列Cがあるので、Cの要素がAからきたかBからきたか判定する、という問題になります。
ここで、配列の全要素は重複しえないため、要素ごとにどちらからきたかという情報をもたせればよいです。
あとはCをソートし、順番に探索してAからきたもののCにおける番号を出力し、つぎにBからきたもののCにおける番号を出力すればよいです。
*/

int main(){
  ll n,m;
  cin >> n >> m;
  vector<ll> a(n),b(m);
  rep(i,n){
    cin >> a[i];
  }
  rep(j,m){
    cin >> b[j];
  }
  vector<pair<ll,bool>> c; //false -> a, true -> b
  rep(i,n){
    c.push_back(make_pair(a[i],false));
  }
  rep(j,m){
    c.push_back(make_pair(b[j],true));
  }
  sort(all(c));
  rep(i,n+m){
    if(!c[i].second){
      cout << i+1 << " ";
    }
  }
  cout << endl;
  rep(i,n+m){
    if(c[i].second){
      cout << i+1 << " ";
    }
  }
  cout << endl;
}