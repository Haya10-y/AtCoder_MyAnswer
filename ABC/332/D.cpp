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
まず，グリッドの行列入れ替えについて重要なこととして行および列ごとに考えられるというものがある．
そのため，行の並び順と列の並び順について考えることができる．
今回はH, Wが非常に小さいため，全列挙しても通る．
二重ループの順列全探索を用いることですべての行列の並び替えについて考えることができる．
並び替えたあとの行列がAと等しければ，何回並び替えたか考えればよい．
これはバブルソートをおこなったうえでスワップ回数を求めることもできるが，転倒数を求めたほうが楽である．
行の並びについての転倒数と列の並びについての転倒数の和が操作回数となる．この最小を全列挙して求めていこう．
計算量はO(H!W! * (H^2 + W^2))程度になり，H,Wが小さいため十分間に合う．
なお，転倒数はBITやSegment Treeを用いることで速く計算できるが，今回は要素数が小さいためその必要はない．
*/

int main(){
  int h,w;
  cin >> h >> w;
  vector<vector<int>> a(h,vector<int>(w)),b(h,vector<int>(w));
  rep(i,h){
    rep(j,w){
      cin >> a[i][j];
    }
  }
  rep(i,h){
    rep(j,w){
      cin >> b[i][j];
    }
  }
  vector<int> row(h), col(w);
  rep(i,h){
    row[i] = i;
  }
  rep(i,w){
    col[i] = i;
  }
  int ans = 1e5;
  int ans_no = 1e5;
  //順列全探索
  do{
    do{
      bool flag = true;
      rep(i,h){
        rep(j,w){
          if(a[i][j] != b[row[i]][col[j]]){
            flag = false;
          }
        }
      }
      if(flag){
        //転倒数の計算
        int inv = 0;
        rep(i,h){
          rep_s(j,i+1,h){
            if(row[i] > row[j]){
              inv++;
            }
          }
        }
        rep(i,w){
          rep_s(j,i+1,w){
            if(col[i] > col[j]){
              inv++;
            }
          }
        }
        ans = min(ans, inv);
      }
    }while(next_permutation(all(col)));
    sort(all(col));
  }while(next_permutation(all(row)));
  if(ans == ans_no){
    cout << -1 << endl;
  }else{
    cout << ans << endl;
  }
  
}