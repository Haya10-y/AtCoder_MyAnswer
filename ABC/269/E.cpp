#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i,n) for(int i = 0; i < n; i++)
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

//問題文：https://atcoder.jp/contests/abc269/tasks/abc269_e
/*
解答方針
1つの行・列に2つのルークが置かれていることがありえない、N-クイーン問題ならぬN-ルーク問題ともいえよう。
N-1個のルークが置かれているので、最後の1個がどこに入るか求めたい。ただし、他のルークの位置はわからないものとする。
ここで、N <= 10^3および20回までしか質問できないことに注目する。ここから大まかな解法を思いつくこともあるだろう。
まず、行・列に対して質問すると考える。このとき、行に対して10回、列に対して10回質問できることになる。
では、どうやって10回でルークのある行・列を特定するのか。
行について考えるとき、すべての列を網羅したうえで行をしぼっていく。
このとき聞いた行の集まりについてルークがすべてあれば、聞いていない方の行の集まりにルークがあることがわかる。
これを繰り返し、ルークのありうる行をしぼっていく。これはいわゆる二分探索である。
計算量はO(logN)であり、実際log2(10^3) = 9.965... < 10であるため、10回質問すれば十分である。
列に対しても同じことをすることで、ルークのある行・列を特定することができる。
実装が少し難しいため、例を挙げつつ実装してみよう。
*/

int main() {
  int n;
  cin >> n;
  //行に対してにぶたんしたあと、列に対してにぶたんする
  int low = 1;
  int high = n;
  int mid = (low+high)/2;
  int row = -1;
  int col = -1;
  //rowの特定, [low, mid]に存在するか聞く
  while(true){
    cout << "? " << low << " " << mid << " " << 1 << " " << n << endl;
    int count;
    cin >> count;
    if(mid-low+1 == count){
      //high側にある
      if(high-low == 1){
        //cout << low << " " << high << endl;
        row = high;
        break;
      }else if(high - low == 0){
        row = high+1;
        break;
      }
      low = mid+1;
      mid = (low+high)/2;
      
    }else{
      //low側にある
      if(high-low <= 1){
        //cout << low << " " << high << endl;
        row = low;
        break;
      }
      high = mid;
      mid = (low+high)/2;
      
    }
    //cout << low << " " << mid << " " << high << endl;
  }
  //cout << "Row End" << endl;
  //colの特定
  low = 1;
  high = n;
  mid = (low+high)/2;
  //初手[1,2], allを見る -> 2個, つぎ0
  while(true){
    cout << "? " << 1 << " " << n << " " << low << " " << mid << endl;
    int count;
    cin >> count;
    if(mid-low+1 == count){
      //high側にある
      if(high-low == 1){
        //cout << low << " " << high << endl;
        col = high;
        break;
      }else if(high - low == 0){
        col = high+1;
        break;
      }
      low = mid+1;
      mid = (low+high)/2;
      
    }else{
      //low側にある
      if(high-low <= 1){
        //cout << low << " " << high << endl;
        col = low;
        break;
      }
      high = mid;
      mid = (low+high)/2;
      
    }
    //cout << low << " " << mid << " " << high << endl;
  }
  cout << "! " << row << " " << col << endl;
}