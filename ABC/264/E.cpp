#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i,n) for(int i = 0; i < n; i++)
#define rep_s(i,s,n) for(int i = s; i < n; i++)
#define rep_r(i,n) for(int i = n-1; i >= 0; i--)
#define rep_rs(i,s,e) for(int i = s-1; i >= e; i--)
#define rep_b(bit,n) for (ll bit = 0; bit < (1<<n); bit++)
#define enum_bit() if(bit & (1<<i))
#define all(a) a.begin(),a.end()
#define sz(v) ((int)v.size())
#define eps 0.00001
#define PI 3.14159265358979323846264338
#include <atcoder/all>
using namespace atcoder;
const int mod1 = 998244353;
const int mod2 = 1000000007;
#define mint modint998244353;

//QCFium法
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

void fast(){
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
}

#define endl "\n" //flushのとき外す

//問題文：https://atcoder.jp/contests/abc264/tasks/abc264_e
/*
解答方針
Union-Findの問題でよくある考え方で、辺を足すのは簡単だが辺を切るのは難しい、というものがある。
実際、辺を切ると電気が消える都市が複数出てくる可能性があるうえにその特定がなかなかできないため難しい。
よって、すべてのイベントが終わった状態から考え、じょじょに辺を繋いでいこう。
まず、電気が通っているかどうかのフラグを各都市・発電所に対してもつ。発電所は確定で電気が通っており、都市の初期状態は電気が通っていない状態である。
ここでグラフをつくって電気が通っているところを広げていきたいが、発電所については一旦考えず、都市だけについて考える。
このとき、片方が光っていればもうひとつを光らせるという処理を入れる。これは発電所も考慮する。これで発電所と直接繋がった要素を光らせることができる。
光った都市から、さらに他の都市に伝播させて光らせていく。これはBFSでできる。
すべての都市についての処理が終わったら、初期状態ができあがる。なお、答えを管理する変数を用意しておく必要があることに注意しよう。
ここからひとつずつ辺を追加し、同様の処理を行っていこう。
後ろのイベントから処理したため、最後に答えを後ろから出力すればよい。
Q回BFSすることから一見計算量が爆発しそうだが、実際はひとつの連結成分について1度しかBFSしないため、全体の計算量はあまり大きくならない。
なお、この問題はUnion-Findでも解くことができる。好きな方法で解いてみよう。
*/

int main(){
  fast();
  int n,m,e;
  cin >> n >> m >> e;
  vector<int> u(e),v(e);
  rep(i,e){
    cin >> u[i] >> v[i];
    u[i]--;v[i]--;
  }
  int q;
  cin >> q;
  vector<int> x(q);
  vector<bool> init(e,true); //全イベント終了時に残っている電線
  rep(i,q){
    cin >> x[i];
    x[i]--;
    init[x[i]] = false;
  }
  //n = 10^5, m = 10^5がありえるため，O(nm)では間に合わない
  //残っている電線をつなぐ
  vector<vector<int>> g(n); //たぶん都市だけにしたほうが楽
  //unlit -> litにするためには
  //litの都市（発電所（always lit））をつなげばいい
  vector<bool> lit(n+m,false); //電気が通っているかどうか
  rep_s(i,n,n+m){
    lit[i] = true; //発電所
  }
  //pushする際にlitにし、他の要素がunlitなら広げてlitにする、ここはbfsでできそう
  //そうでなければ全部litなので省略
  int ans = 0;
  vector<int> ans_all;
  rep(i,e){
    if(init[i]){
      if(u[i] < n && v[i] < n){
        g[u[i]].push_back(v[i]);
        g[v[i]].push_back(u[i]);
      }
      int start = -1; //unlitなやつ
      if(!lit[u[i]] && lit[v[i]]){
        lit[u[i]] = true;
        ans++;
        start = u[i];
      }else if(lit[u[i]] && !lit[v[i]]){
        lit[v[i]] = true;
        ans++;
        start = v[i];
      }
      //lit[u[i]] xor lit[v[i]] == 1ならやる
      if(start != -1){ //unlit側を調べる
        //cout << start  << " " <<sz(g[start])<< endl;
        if(sz(g[start]) > 0 && !lit[g[start][0]]){
          //bfs開始、通った点すべてをlitにする
          queue<int> bfs;
          bfs.push(start);
          while(!bfs.empty()){
            int node = bfs.front();
            bfs.pop();
            if(!lit[node]){
              ans++;
            }
            lit[node] = true;
            for(auto j: g[node]){
              if(lit[j]){
                continue;
              }
              bfs.push(j);
            }
          }
        }
      }
    }
  }
  ans_all.push_back(ans);
  rep_r(i,q){
    if(u[x[i]] < n && v[x[i]] < n){
      g[u[x[i]]].push_back(v[x[i]]);
      g[v[x[i]]].push_back(u[x[i]]);
    }
    int start = -1; //unlitなやつ
    if(!lit[u[x[i]]] && lit[v[x[i]]]){
      lit[u[x[i]]] = true;
      ans++;
      start = u[x[i]];
    }else if(lit[u[x[i]]] && !lit[v[x[i]]]){
      lit[v[x[i]]] = true;
      ans++;
      start = v[x[i]];
    }
    if(start != -1){ //unlit側を調べる
      //cout << start  << " " <<sz(g[start])<< endl;
      if(sz(g[start]) > 0 && !lit[g[start][0]]){
        //bfs開始、通った点すべてをlitにする
        queue<int> bfs;
        bfs.push(start);
        while(!bfs.empty()){
          int node = bfs.front();
          bfs.pop();
          if(!lit[node]){
            ans++;
          }
          lit[node] = true;
          for(auto j: g[node]){
            if(lit[j]){
              continue;
            }
            bfs.push(j);
          }
        }
      }
    }
    ans_all.push_back(ans);
    /*rep(i,n){
      cout << lit[i] << " ";
    }
    cout << endl;*/
  }
  rep_r(i,q){
    cout << ans_all[i] << endl;;
  }
  
}