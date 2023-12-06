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
mexをとる問題は、mexとなりうる値をsetに入れることが有用である可能性が高い。
ここでmexとなりうる値はたかだかN以下なので、最初にsetに入れる際の計算量はO(NlogN)になる。
あとは整数ごとのカウントをとり、クエリごとに更新してカウントが0 -> 1になったらsetから外し、1 -> 0になったらsetに入れればよい。
この作業はO(QlogN)で終わり、答えはsetの一番最初の値である。全体の計算量はO((N+Q)logN)くらい。
*/

int main(){
  fast();
  int n,q;
  cin >> n >> q;
  vector<int> a(n);
  rep(i,n){
    cin >> a[i];
  }
  unordered_map<int,int> mp;
  rep(i,n){
    mp[a[i]]++;
  }
  //mex値はたかだかnにおさまる
  set<int> mex;
  rep(i,n+2){
    mex.insert(i);
  }
  //*mex.begin()が求める値
  rep(i,n){
    mex.erase(a[i]);
  }
  int i,x;
  rep(j,q){
    cin >> i >> x;
    i--;
    mp[a[i]]--;
    if(mp[a[i]] == 0){
      mex.insert(a[i]);
    }
    a[i] = x;
    if(mp[a[i]] == 0){
      mex.erase(a[i]);
    }
    mp[a[i]]++;
    cout << *mex.begin() << endl;
  }
}