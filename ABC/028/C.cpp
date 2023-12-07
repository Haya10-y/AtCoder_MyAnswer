#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(ll i = 0; i < n; i++)
#define rep_s(i,s,n) for(ll i = s; i < n; i++)
#define rep_r(i,n) for(ll i = n-1; i >= 0; i--)

/*
解答方針
5つの数のうち、3つの組み合わせをすべて列挙して和を求める。
全列挙には三重ループを用いればよい。
和に関しては次々配列に入れたうえで最後にソートしたが、本来なら重複なし集合setを使ったほうが安全である。
"3番目に大きいもの"を出す都合上、A+D+EかB+C+Eが必ず答えになるが…
*/

int main(){
  vector<ll> num(5);
  rep(i,5){
    cin >> num[i];
  }
  vector<ll> sum;
  rep(i,5){
    rep_s(j,i+1,5){
      rep_s(k,j+1,5){
        sum.push_back(num[i]+num[j]+num[k]);
      }
    }
  }
  sort(sum.begin(), sum.end(),greater());
  rep(i,(ll)sum.size()){
    cerr << sum[i] << " ";
  }
  cout << sum[2] << endl;
}