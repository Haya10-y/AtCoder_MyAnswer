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
問題文は難しそうだが，出力例と龍の形を考えると中心から外に向かってぐるぐる回していけば通りそう．
最初だけ処理に注意しておき，中心の上下左右のどれかから時計回りまたは反時計回りに回していこう．
外からやってもいいし，内からやってもいい．ただ外からやったほうが楽だろう．
*/

int main(){
  int n;
  cin >> n;
  vector<vector<string>> ans(n,vector<string>(n,"."));
  int center = n/2;
  ans[center][center] = "T";
  //ぐるぐるやれば間違いなく通るので、真上からスタートして右、下、左、上とやりたい
  int num = n*n-1;
  //最初だけがんばる
  vector<int> dx = {0,1,1,1,0,-1,-1,-1};
  vector<int> dy = {-1,-1,0,1,1,1,0,-1};
  rep(i,8){
    ans[center+dy[i]][center+dx[i]] = to_string(num);
    num--;
  }

  int len = 4; //初期値は4
  dy = {0,1,0,-1};
  dx = {1,0,-1,0};
  rep(i,(n-3)/2){ //repeat回数は(n-3)/2回
    int y = center-i-2;
    int x = center-i-2;
    rep(j,4){
      rep(k,len){
        y+=dy[j];
        x+=dx[j];
        ans[y][x] = to_string(num);
        num--;
      }
    }
    len+=2;
  }
  rep(i,n){
    rep(j,n){
      cout << ans[i][j] << " ";
    }
    cout << endl;
  }
}