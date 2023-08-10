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

//問題文：https://atcoder.jp/contests/abc278/tasks/abc278_e
/*
解答方針
2次元グリッドに対して、2つの長方形にある整数のカウントとその差分を求めたい。こういうときは2次元累積和が使える。
整数の種類はたかだかN <= 300種類であるため、O(HWN)くらいであれば間に合う。
N種類の整数についてカウントを行うが、そのときに2次元累積和をつかって計算しておく。計算量はO(HWN)になる。
そこから各k,lについて処理を行うが、ここは最大でもO(HWN)で終わる。よって全体の計算量はO(HWN)になる。
*/

int main(){
  ll H,W,n,h,w;
  cin >> H >> W >> n >> h >> w;
  vector<vector<ll>> a(H,vector<ll>(W));
  vector<ll> v(n+1,0);
  rep(i,H){
    rep(j,W){
      cin >> a[i][j];
      v[a[i][j]]++;
    }
  }
  //愚直にやる→最大で150*150を150*150回繰り返す可能性あり→5*10^8回程度、間に合うか不明
  //横方向の集合をとり、h行マージしたい
  vector<vector<vector<ll>>> hor_v(H,vector<vector<ll>>(W-w+1, vector<ll>(n+1)));
  //縦方向も引き算をつかいたいのでとっておく
  vector<vector<vector<ll>>> ver_v(W,vector<vector<ll>>(H-h+1, vector<ll>(n+1)));
  //O(Hw)
  rep(i,H){
    rep(j,w){
      hor_v[i][0][a[i][j]]++;
    }
  }
  //O(hW)
  rep(i,W){
    rep(j,h){
      ver_v[i][0][a[j][i]]++;
    }
  }
  //横方向のmapを求める、O(H(W-w))
  rep(i,H){
    rep_s(j,1,W-w+1){
      hor_v[i][j] = hor_v[i][j-1];
      hor_v[i][j][a[i][j-1]]--; //hor[0][1][a[0][0]]--;
      hor_v[i][j][a[i][j+w-1]]++; //hor[0][1][a[0][2]]++;
    }
  }
  //hor[i][j] -> i行j番目のmap
  
  //縦方向のmapを求める、O((H-h)W)
  rep(i,W){
    rep_s(j,1,H-h+1){
      ver_v[i][j] = ver_v[i][j-1];
      ver_v[i][j][a[j-1][i]]--;
      ver_v[i][j][a[j+h-1][i]]++;
    }
  }
  //ver[i][j] -> i列j番目のmap
  
  //いちいちmergeしているとTLE、素早く解くためには…？
  //1行、1列ずつadd,subする？ -> そのままだとTLE、ループ回数を減らすためには？
  //横方向に動かす→w*h回
  //縦方向に動かす→w*h回
  //unordered_map<ll,ll> start;
  vector<ll> start_v(n+1,0);
  //tmpの初期値をつくる
  rep(i,H-h+1){
    vector<ll> tmp_v;
    rep(j,W-w+1){
      if(i == 0 && j == 0){
        //1度だけ、O(hN)
        rep(k,h){
          rep(l,n+1){
            start_v[l] += hor_v[k][0][l];
          }
  		}
        tmp_v = start_v;
      }else if(j == 0){
        rep(k,n+1){
          start_v[k] += hor_v[i+h-1][0][k];
          start_v[k] -= hor_v[i-1][0][k];
        }
        tmp_v = start_v;
      }else{
        rep(k,n+1){
          tmp_v[k] += ver_v[j+w-1][i][k];
          tmp_v[k] -= ver_v[j-1][i][k];
        }
      }
      ll ans = 0;
      rep(i,n+1){
        if(tmp_v[i] < v[i]){
          ans++;
        }
      }
      cout << ans << " ";
    }
    cout << endl;
  }
}