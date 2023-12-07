#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(ll i = 0; i < n; i++)
#define rep_s(i,s,n) for(ll i = s; i < n; i++)
#define rep_r(i,n) for(ll i = n-1; i >= 0; i--)
#define rep_b(bit,n) for (ll bit = 0; bit < (1<<n); bit++)
#define enum_bit() if(bit & (1<<i))
#define debug(x) cerr << x << endl
#define debug_s(x) cerr << x << " "
#define debug_t(x,y) cerr << x << " " << y << endl
#define all(a) a.begin(),a.end()
#define sz(v) ((ll)v.size())

/*
解答方針
色の種類数を求めたい。
ここで、レート3199以下の色は固定であるため、そこについてはそのまま実装すればよい。
問題はレート3200以上の任意色であり、ここについて考える必要がある。
コンテストの参加者に3200未満の人がいれば、3200以上の人はそこに合わせることで種類数の最小値を得ることができる。
ただし、全員3200以上である場合はどれかの色ひとつに合わせる必要がある。この場合は1種類になる。
色の種類数の最大値に関しては、任意色の人がそれぞれ違う色をとればよい。
なお、20231207現在、AtCoder上の任意色の人は42人しかいない。こわいね。
*/

int main(){
  ll n;
  cin >> n;
  vector<ll> v(9);
  bool hasundergod = false;
  rep(i,n){
    ll a;
    cin >> a;
    if(1 <= a && a <= 399){
      v[0]++;
      hasundergod = true;
    }else if(400 <= a && a <= 799){
      v[1]++;
      hasundergod = true;
    }else if(800 <= a && a <= 1199){
      v[2]++;
      hasundergod = true;
    }else if(1200 <= a && a <= 1599){
      v[3]++;
      hasundergod = true;
    }else if(1600 <= a && a <= 1999){
      v[4]++;
      hasundergod = true;
    }else if(2000 <= a && a <= 2399){
      v[5]++;
      hasundergod = true;
    }else if(2400 <= a && a <= 2799){
      v[6]++;
      hasundergod = true;
    }else if(2800 <= a && a <= 3199){
      v[7]++;
      hasundergod = true;
    }else{
      v[8]++;
    }
  }
  ll min = 0;
  ll max = 0;
  rep(i,8){
    if(v[i] != 0){
      min++;
      max++;
    }
  }
  if(hasundergod){
    max = min+v[8];
  }else{
    min = 1;
    max = v[8];
  }
  cout << min << " " << max << endl;
}