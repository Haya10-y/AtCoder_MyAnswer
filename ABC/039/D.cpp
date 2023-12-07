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
#define mod1 998244353
#define mod2 1000000007

/*
解答方針
かなりの重実装問題。コーナーケースに気をつけつつ実装しよう。
実際に収縮と逆の作業を行ったあと、もう一度収縮を行ってもとの画像と等しくなれば条件を満たす画像が一意に定まる。
ここでは収縮後の画像をs、もとの画像をt、tを再収縮したものをresとしている。sとresが等しければ収縮前画像が一意に定まる。
*/

int main(){
  ll h,w;
  cin >> h >> w;
  vector<string> s(h);
  rep(i,h){
    cin >> s[i];
  }
  vector<vector<char>> t(h,vector<char>(w,'.')); //ws
  //コーナーケース：w=1,h=1
  if(w == 1 && h == 1){
    cout << "possible" << endl;
    cout << s[0] << endl;
  }
  //コーナーケース：w=1
  if(w == 1){
    vector<char> t(h,'#');
    rep(i,h){
      rep_s(j,-1,2){
        if(i+j >= 0 && i+j < h && s[i+j][0] == '.'){
          t[i] = '.';
        }
      }
    }
    vector<char> res(h,'.');
    rep(i,h){
      if(t[i] == '#'){
        rep_s(j,-1,2){
          if(i+j >= 0 && i+j < h){
            res[i+j] = '#';
          }
        }
      }
    }
    rep(i,h){
      if(res[i] != s[i][0]){
        cout << "impossible" << endl;
        return 0;
      }
    }
    cout << "possible" << endl;
    rep(i,h){
      cout << t[i] << endl;
    }
    return 0;
  }
  
  //コーナーケース：h=1
  if(h == 1){
    vector<char> t(w,'#');
    rep(i,w){
      rep_s(j,-1,2){
        if(i+j >= 0 && i+j < w && s[0][i+j] == '.'){
          t[i] = '.';
        }
      }
    }
    vector<char> res(w,'.');
    rep(i,h){
      if(t[i] == '#'){
        rep_s(j,-1,2){
          if(i+j >= 0 && i+j < h){
            res[i+j] = '#';
          }
        }
      }
    }
    rep(i,h){
      if(res[i] != s[0][i]){
        cout << "impossible" << endl;
        return 0;
      }
    }
    cout << "possible" << endl;
    rep(i,w){
      cout << t[i];
    }
    cout << endl;
    return 0;
    
  }
  //まず圧縮して復元し、s=tかを見る
  //コーナーケース：四隅
  vector<ll> count_corner(4,0);
  rep(i,2){
    rep(j,2){
      if(s[i][j] == '#'){
        count_corner[0]++;
      }
      if(s[h-i-1][j] == '#'){
        count_corner[1]++;
      }
      if(s[i][w-j-1] == '#'){
        count_corner[2]++;
      }
      if(s[h-i-1][w-j-1] == '#'){
        count_corner[3]++;
      }
    }
  }
  if(count_corner[0] == 4){
    t[0][0] = '#';
  }
  if(count_corner[1] == 4){
    t[h-1][0] = '#';
  }
  if(count_corner[2] == 4){
    t[0][w-1] = '#';
  }
  if(count_corner[3] == 4){
    t[h-1][w-1] = '#';
  }
  
  //コーナーケース：四辺
  rep_s(i,1,w-1){
    ll count_up = 0;
    ll count_down = 0;
    rep(j,2){
      rep_s(k,i-1,i+2){
        if(s[j][k] == '#'){
          count_up++;
        }
        if(s[h-j-1][k] == '#'){
          count_down++;
        }
      }
    }
    if(count_up == 6){
      t[0][i] = '#';
    }
    if(count_down == 6){
      t[h-1][i] = '#';
    }
  }
  
  rep_s(i,1,h-1){
    ll count_left = 0;
    ll count_right = 0;
    rep_s(j,i-1,i+2){
      rep(k,2){
        if(s[j][k] == '#'){
          count_left++;
        }
        if(s[j][w-k-1] == '#'){
          count_right++;
        }
      }
    }
    if(count_left == 6){
      t[i][0] = '#';
    }
    if(count_right == 6){
      t[i][w-1] = '#';
    }
  }
  
  rep_s(i,1,h-1){
    rep_s(j,1,w-1){
      ll count = 0;
      rep_s(k,i-1,i+2){
        rep_s(l,j-1,j+2){
          if(s[k][l] == '#'){
            count++;
          }
        }
      }
      if(count == 9){
        t[i][j] = '#';
      }
    }
  }
  
  //復元
  vector<vector<char>> res(h,vector<char>(w,'.'));
  rep(i,h){
    rep(j,w){
      if(t[i][j] == '#'){
        rep_s(k,-1,2){
          rep_s(l,-1,2){
            if(i+k >= 0 && i+k < h && j+l >= 0 && j+l < w){
              res[i+k][j+l] = '#';
            }
          }
        } 
      }
    }
  }
  
  rep(i,h){
    rep(j,w){
      if(s[i][j] != res[i][j]){
        cout << "impossible" << endl;
        return 0;
      }
    }
  }
  cout << "possible" << endl;
  rep(i,h){
    rep(j,w){
      cout << t[i][j];
    }
    cout << endl;
  }
}