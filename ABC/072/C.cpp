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
Xのとりうる値は-1 <= X <= 100001と考えてよい。
まずは整数列を走査し、現れる整数をカウントしていく。
a_iの値はX-1, X, X+1の3パターンが考えられるため、これらの3パターンを満たす整数の個数を求めていく。
最終的に求めるのはXの値でなく、Xを選んだときにa_i = Xとなるiの最大個数である。
*/

int main(){
  ll n;
  cin >> n;
  
  map<ll,ll> mp;
  rep(i,n){
    ll tmp;
    cin >> tmp;
    mp[tmp]++;
  }
  ll ans = 0;

  rep_s(x,-1,100001){
    ll tmp = mp[x-1]+mp[x]+mp[x+1];
    ans = max(tmp,ans);
    
  }
  cout << ans << endl;
}