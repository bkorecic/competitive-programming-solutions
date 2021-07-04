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
  sort(nums.begin(), nums.end());
  ll sum = 0;
  for(int i=0; i<n; i++){
    if(nums[i] > sum+1) break;
    sum += nums[i];
  }
  cout << sum+1 << '\n';
  return 0;
}
