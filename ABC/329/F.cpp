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
マージテクとよばれる手法を用いる。
大きい方のsetを小さい方のsetにマージすると時間がかかるが、小さい方を大きい方にマージすることでより短い時間でマージすることが可能になる。
ボールの種類数はたかだかN個であるため、ボールの移動回数をO(NlogN)程度で抑えることができる。
箱の番号を別個に管理しておき、大きい方から小さい方に移すときには番号の入れ替えを行おう。
*/

int main(){
  fast();
  int n,q;
  cin >> n >> q;
  vector<int> c(n);
  rep(i,n){
    cin >> c[i];
  }
  vector<int> idx(n); //移動後のidxをとる
  rep(i,n){
    idx[i] = i;
  }
  
  unordered_set<int> emp;
  vector<unordered_set<int>> box(n);
  rep(i,n){
    box[i].insert(c[i]);
  }
  
  int a,b;
  rep(i,q){
    cin >> a >> b;
    a--;b--;
    //サイズの確認、sz(box[idx[a]]) < sz(box[idx[b]])前提で進める
    if(sz(box[idx[a]]) >= sz(box[idx[b]])){
      swap(idx[a],idx[b]);
    }
    //cout << idx[a] << " " << sz(box[idx[a]]) << ", " << idx[b] << " " << sz(box[idx[b]]) << endl;
    //cout << sz(box[idx[a]]) << " " << sz(box[idx[b]]) << endl;
    for(auto elem: box[idx[a]]){
      box[idx[b]].insert(elem);
    }
    //小さい方を消す
    
    box[idx[a]].clear();
    /*for(auto elem: box[idx[b]]){
      cout << elem << " ";
    }
    cout << endl;*/
    cout << sz(box[idx[b]]) << endl;
  }
}