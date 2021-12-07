#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "dbg.h"
#else
#define dbg(...) 1313
#endif

typedef long long ll;

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  vector <int> nums;
  ll x;
  ll mx=0;
  while(cin >> x){
    nums.push_back(x);
    cin.ignore();
    mx = max(mx, x);
  }
  sort(nums.begin(), nums.end());
  ll ans=1e18;
  int n = nums.size();
  for(ll i=0; i<=mx; i++){
    ll lans=0;
    for(int j=0; j<n; j++){
      ll dist = abs(i-nums[j]);
      lans += dist*(dist+1)/2;
    }
    ans = min(ans, lans);
  }
  cout << ans << '\n';
  return 0;
}
