#include <bits/stdc++.h>
#define f first
#define s second
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, k; cin >> n >> k;
  vector <int> nums(n);
  for(int i=0; i<n; i++) cin >> nums[i];
  map <int, int> freq;
  ll ans = 0;
  int l = 0;
  int d = 0;
  for(int r=0; r<n; r++){
    d += freq[nums[r]] == 0;
    freq[nums[r]]++;
    while(d > k){
      d -= freq[nums[l]] == 1;
      freq[nums[l]]--;
      l++;
    }
    ans += r-l+1;
  }
  cout << ans << '\n';
  return 0;
}
