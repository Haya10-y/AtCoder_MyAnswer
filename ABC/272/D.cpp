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

//問題文：https://atcoder.jp/contests/abc272/tasks/abc272_d
/*
解答方針
コマを動かした最小回数を聞かれているので、最短経路問題と同じ手法が使えそうです。つまり、BFSを使えばよいことになります。
ひとつひとつのマスをグラフの頂点と考え、移動できるところに対して辺を張って考えます。
移動するときのベクトルは事前に求めておき、各マスにおいてそのベクトルを加算することで次に移動するマスを求めることができます。
あとは(1,1)からBFSを行うだけです。実装が少々面倒ですが考察は難しくありません。
*/

int main(){
  ll n,m;
  cin >> n >> m;
  vector<vector<ll>> field(n,vector<ll>(n,-1));
  vector<vector<bool>> visited(n,vector<bool>(n,false));
  queue<pair<ll,ll>> nextpos;
  vector<pair<ll,ll>> move_all;
  rep(i,m+1){
    ll j2 = m-i*i;
    if(j2 < i*i){
      break;
    }
    if(fmod(sqrt(j2),1.0) != 0.0){
      continue;
    }
    ll j = sqrt(j2);
    move_all.push_back(make_pair(i,j));
  }
  /*rep(i,sz(move_all)){
    cout << move_all[i].first << " " <<move_all[i].second << endl;
  }*/
  
  //ここまでO(m)
  //BFSで解くところまではわかった、あとはしらん
  nextpos.push(make_pair(0,0));
  field[0][0] = 0;
  while(!nextpos.empty()){
    //cout << "loop" << endl;
    ll y = nextpos.front().first;
    ll x = nextpos.front().second;
    nextpos.pop();
    if(visited[y][x]){
      continue;
    }
    for(auto move: move_all){
    if(move.first != move.second){
      if(y+move.second <= n-1 && x+move.first <= n-1 && !visited[y+move.second][x+move.first]){
        //cout << "pushed1" << endl;
        nextpos.push(make_pair(y+move.second,x+move.first));
        field[y+move.second][x+move.first] = field[y][x] + 1;
        
      }
      if(y-move.second >= 0 && x+move.first <= n-1 && !visited[y-move.second][x+move.first]){
        //cout << "pushed2" << endl;
        nextpos.push(make_pair(y-move.second,x+move.first));
        field[y-move.second][x+move.first] = field[y][x] + 1;
        
      }
      if(y+move.second <= n-1 && x-move.first >= 0 && !visited[y+move.second][x-move.first]){
        //cout << "pushed3" << endl;
        nextpos.push(make_pair(y+move.second,x-move.first));
        field[y+move.second][x-move.first] = field[y][x] + 1;
        
      }
      if(y-move.second >= 0 && x-move.first >= 0 && !visited[y-move.second][x-move.first]){
        //cout << "pushed4" << endl;
        nextpos.push(make_pair(y-move.second,x-move.first));
        field[y-move.second][x-move.first] = field[y][x] + 1;
        
      }
    }
    if(y+move.first <= n-1 && x+move.second <= n-1 && !visited[y+move.first][x+move.second]){
      //cout << "pushed5" << endl;
      nextpos.push(make_pair(y+move.first,x+move.second));
      field[y+move.first][x+move.second] = field[y][x] + 1;
      
    }
    if(y-move.first >= 0 && x+move.second <= n-1 && !visited[y-move.first][x+move.second]){
      //cout << "pushed6" << endl;
      nextpos.push(make_pair(y-move.first,x+move.second));
      field[y-move.first][x+move.second] = field[y][x] + 1;
      
    }
    if(y+move.first <= n-1 && x-move.second >= 0 && !visited[y+move.first][x-move.second]){
      //cout << "pushed7" << endl;
      nextpos.push(make_pair(y+move.first,x-move.second));
      field[y+move.first][x-move.second] = field[y][x] + 1;
      
    }
    if(y-move.first >= 0 && x-move.second >= 0 && !visited[y-move.first][x-move.second]){
      //cout << "pushed8" << endl;
      nextpos.push(make_pair(y-move.first,x-move.second));
      field[y-move.first][x-move.second] = field[y][x] + 1;
      
    }
    }
    
    visited[y][x] = true;
  }
  rep(i,n){
    rep(j,n){
      cout << field[i][j] << " ";
    }
    cout << endl;
  }
}