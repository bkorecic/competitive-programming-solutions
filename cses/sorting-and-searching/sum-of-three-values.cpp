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
  vector <pair<ll,int>> nums(n);
  for(int i=0; i<n; i++){
    cin >> nums[i].f;
    nums[i].s = i+1;
  }
  sort(nums.begin(), nums.end());
  for(int i=1; i<n-1; i++){
    for(int j=i+1; j<n; j++){
      // nums[i] + nums[j] + ?? = x
      ll target = x - nums[i].f - nums[j].f;
      int l=0, r=i-1, mid;
      while(l < r){
        mid = (l+r)/2;
        if(nums[mid].f >= target) r = mid;
        else l = mid+1;
      }
      if(nums[l].f == target){
        cout << nums[l].s << ' ' << nums[i].s << ' ' << nums[j].s << '\n';
        return 0;
      }
    }
  }
  cout << "IMPOSSIBLE\n";
  return 0;
}
