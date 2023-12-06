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
ナンプレの解答が正しいものか確認する問題。
縦、横、3*3の四角について同じ文字がないか確認したい。
これはbool型の配列を使ったり、setを使ったりすることで解くことができる。
縦横に関しては簡単だが、四角の判定が若干曲者なので、実装方法を考えよう。
9ブロックのうちどのブロックにあるかを判定し、そのあと3*3の範囲を探せばよい。
始点に関してはブロックの縦方向の座標、横方向の座標を3倍すればよい。
*/

int main(){
  vector<vector<int>> a(9,vector<int>(9));
  rep(i,9){
    rep(j,9){
      cin >> a[i][j];
    }
  }
  //horizontal
  rep(i,9){
    set<int> st;
    rep(j,9){
      if(st.count(a[i][j])){
        cout << "No" << endl;
        return 0;
      }else{
        st.insert(a[i][j]);
      }
    }
  }
  
  //vertical
  rep(i,9){
    set<int> st;
    rep(j,9){
      if(st.count(a[j][i])){
        cout << "No" << endl;
        return 0;
      }else{
        st.insert(a[j][i]);
      }
    }
  }
  
  //square
  rep(di,3){
    rep(dj,3){
      set<int> st;
      rep(i,3){
        rep(j,3){
          if(st.count(a[di*3+i][dj*3+j])){
            cout << "No" << endl;
            return 0;
          }else{
            st.insert(a[di*3+i][dj*3+j]);
          }
        }
      }
    }
  }
  cout << "Yes" << endl;
}