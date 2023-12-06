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
最短経路問題なので、ダイクストラ法が使えそう。
ここで、社用車から電車に乗り換えたあと、電車から社用車に乗り換えることはできない。
つまり、電車に乗ったあとは目的地までそのまま進み続けることになる。
まず初めに社用車に乗った際の移動時間から考えよう。
始点は都市1しかないため、最初は都市1だけを入れた状態で社用車についてダイクストラする。
これで都市1からすべての都市への社用車を用いた移動時間を求められる。
次に任意のタイミングで電車に乗り換えられることから、全都市の社用車での所要時間を入れてから電車についてダイクストラする。
はじめに複数点をpriority_queueに入れておく手法は通称拡張ダイクストラと呼ばれる。
あとは都市Nまでの所要時間を出力すればよい。計算量は遅くともO(N^2 logN)程度であり、十分間に合う。
*/

int main(){
  fast();
  int n;
  ll a,b,c;
  cin >> n >> a >> b >> c;
  vector<vector<ll>> d(n,vector<ll>(n));
  rep(i,n){
    rep(j,n){
      cin >> d[i][j];
    }
  }
  vector<ll> dist_car(n,1e17);
  vector<ll> dist_train(n,1e17);
  dist_car[0] = 0;
  dist_train[0] = 0;
  //まず車だけでダイクストラ
  priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> pq; //{dist,idx}をもつ
  pq.push(make_pair(0,0));
  ll dist;
  int idx;
  pair<ll,int> p;
  while(!pq.empty()){
    p = pq.top();
    pq.pop();
    dist = p.first;
    idx = p.second;
    rep(i,n){
      if(d[idx][i] != 0){
        //pqに入れるか判定
        if(dist_car[i] > dist_car[idx] + d[idx][i]*a){
          dist_car[i] = dist_car[idx] + d[idx][i]*a;
          dist_train[i] = dist_car[i]; //電車分を先に更新しておく
          pq.push(make_pair(dist_car[i], i));
        }
      }
    }
  }
  
  //つぎに電車でダイクストラ、ここは拡張ダイクストラで
  rep(i,n){
    pq.push(make_pair(dist_train[i], i));
  }
  
  while(!pq.empty()){
    p = pq.top();
    pq.pop();
    dist = p.first;
    idx = p.second;
    rep(i,n){
      if(d[idx][i] != 0){
        if(dist_train[i] > dist_train[idx] + d[idx][i]*b+c){
          dist_train[i] = dist_train[idx]+d[idx][i]*b+c;
          pq.push(make_pair(dist_train[i], i));
        }
      }
    }
  }
  
  cout << dist_train[n-1] << endl;
}