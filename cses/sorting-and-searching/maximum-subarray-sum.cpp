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
  ll ans = -1e18;
  ll cur_sum = 0;
  for(int i=0; i<n; i++){
    ll x; cin >> x;
    cur_sum += x;
    ans = max(ans, cur_sum);
    if(cur_sum < 0) cur_sum = 0;
  }
  cout << ans << '\n';
  return 0;
}
