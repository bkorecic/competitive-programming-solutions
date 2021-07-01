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
  map <int, int> nums;
  for(int i=0; i<n; i++){
    int cur; cin >> cur;
    if(nums.count(x-cur)){
      cout << i+1 << ' ' << nums[x-cur]+1 << '\n';
      return 0;
    }
    nums[cur] = i;
  }
  cout << "IMPOSSIBLE\n";
  return 0;
}
