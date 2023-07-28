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

//問題文：https://atcoder.jp/contests/abc310/tasks/abc310_b
/*
解答方針：
重実装問題です。問題文通りに頑張る必要があります。
製品がもつ機能はsetでまとめ、比較の際にはマージしたsetと比較するとよいです。
O(N^2)が余裕で間に合うので、特別な処理は不要です。ただただ実装力が問われる問題です。
*/

int main(){
  int n,m;
  cin >> n >> m;
  vector<pair<int,set<int>>> pf(n);
  rep(i,n){
    cin >> pf[i].first;
    int c,tmp;
    cin >> c;
    rep(j,c){
      cin >> tmp;
      //cout << tmp << endl;
      pf[i].second.insert(tmp);
    }
  }
  bool flag = false;
  rep(i,n){
    rep(j,n){
      if(i == j)continue;
      if(pf[i].first < pf[j].first){
        continue;
      }
      set<int> tmp = pf[j].second;
      for(auto k: pf[i].second){
        tmp.insert(k);
      }
      if(tmp != pf[j].second){
        continue;
      }
      bool flag2 = false;
      for(auto k:pf[j].second){
        if(!pf[i].second.count(k))flag2 = true;
      }
      if(pf[i].first > pf[j].first || flag2){
        flag = true;
        //cout << i << " " << j << endl;
      }
    }
  }
  /*rep(i,n){
    for(auto j: pf[i].second){
      cout << j << " ";
    }
    cout << endl;
  }*/
  if(flag){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }
}