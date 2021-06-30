#include <bits/stdc++.h>
#define f first
#define s second
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n; cin >> n;
  vector <ll> w(n);
  ll total_sum=0;
  for(int i=0; i<n; i++){
    cin >> w[i];
    total_sum += w[i];
  }
  ll ans = 1e12;
  for(int bitmask=0; bitmask<=(1<<n)-1; bitmask++){
    ll group_sum = 0;
    for(int i=0; i<n; i++){
      if(bitmask & (1<<i)) group_sum += w[i];
    }
    ans = min(ans, abs(group_sum - (total_sum-group_sum)));
  }
  cout << ans << '\n'; 

  return 0;
}
