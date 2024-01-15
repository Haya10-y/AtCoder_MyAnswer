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
#define pii pair<int,int>
#define pll pair<ll,ll>
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
龍のパーツiは，移動ごとにパーツi-1の位置に動く．また，移動回数がi回を超えるとパーツ1の軌跡をたどることになる．
そのため，パーツ1の軌跡を記録しておくことが重要になる．
移動ごとにパーツ1の座標を記録していき，移動回数をカウントする．
座標を聞かれたらパーツ番号と移動回数を比較し，移動回数が大きければ残った移動回数分だけパーツ1の軌跡をみる．
パーツ番号が大きければその番号から移動回数を引けばよい．
軌跡の記録はO(Q)で，参照はO(1)でできるため，全体の計算量としてはO(N+Q)となる．
*/

int main(){
  int n,q;
  cin >> n >> q;
  //最初は{(1,0),(2,0),(3,0),...,(n,0)}.
  int y1 = 0;
  int x1 = 1;
  //移動回数ごとの座標値を記録しておくとよさそう
  int dy = 0;
  int dx = 0;
  int cnt = 0;
  vector<pair<int,int>> move;
  //move.push_back(dx,dy);
  int num,idx;
  char query;
  unordered_map<char,pair<int,int>> mp;
  mp['L'] = {-1,0};
  mp['R'] = {1,0};
  mp['U'] = {0,1};
  mp['D'] = {0,-1};
  rep(i,q){
    cin >> num;
    if(num == 1){
      cin >> query;
      dx += mp[query].first;
      dy += mp[query].second;
      move.push_back({dx,dy});
      cnt++;
    }else{
      cin >> idx;
      idx -= cnt;
      if(idx <= 0){
        idx *= -1;
        cout << 1+move[idx].first << " " << 0+move[idx].second << endl;
      }else{
        cout << idx << " " << 0 << endl;
      }
    }
  }
}