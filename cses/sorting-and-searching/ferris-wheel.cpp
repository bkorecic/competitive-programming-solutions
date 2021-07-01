#include <bits/stdc++.h>
#define f first
#define s second
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, x; cin >> n >> x;
  vector <int> nums(n);
  for(int i=0; i<n; i++) cin >> nums[i];
  sort(nums.begin(), nums.end());
  int ans = 0, i = 0, j = n-1;
  while(i <= j){
    if(nums[i] + nums[j] > x) j--;
    else{ // take both
      i++;
      j--;
    }
    ans++;
  }
  cout << ans << '\n';
  return 0;
}
