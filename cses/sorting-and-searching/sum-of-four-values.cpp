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
  ll x; cin >> x;
  if(n<4){
    cout << "IMPOSSIBLE\n";
    return 0;
  }
  vector <ll> nums(n);
  for(int i=0; i<n; i++) cin >> nums[i];
  map <ll, pair<int,int>> sums = {{nums[0]+nums[1], {0, 1}}};
  for(int i=2; i<n-1; i++){
    for(int j=i+1; j<n; j++){
      ll target = x-nums[i]-nums[j];
      if(sums.count(target)){
        cout << sums[target].f+1 << ' ' << sums[target].s+1 << ' ' << i+1 << ' ' << j+1 << '\n';
        return 0;
      }
    }
    for(int j=0; j<i; j++){
      sums[nums[i]+nums[j]] = {j, i};
    }
  }
  cout << "IMPOSSIBLE\n";
  return 0;
}
