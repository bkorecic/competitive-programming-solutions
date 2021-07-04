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
  vector <pair<int,int>> nums(n);
  for(int i=0; i<n; i++){
    cin >> nums[i].f;
    nums[i].s = i;
  }
  sort(nums.begin(), nums.end());
  int ans = 1;
  for(int i=0; i<n-1; i++){
    if(nums[i].s > nums[i+1].s) ans++;
  }
  cout << ans << '\n';
  return 0;
}
