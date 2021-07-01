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
  vector <int> nums(n);
  for(int i=0; i<n; i++) cin >> nums[i];
  ll l = 0, r = 1e9, mid;
  auto calc = [&](ll target){
    ll ans = 0;
    for(int i=0; i<n; i++){
      ans += abs(nums[i]-target);
    }
    return ans;
  };
  while(l < r){
    mid = (l+r)/2;
    if(calc(mid) >= calc(mid-1))
      r = mid;
    else
      l = mid+1;
  }
  cout << calc(l-1) << '\n';
  return 0;
}
