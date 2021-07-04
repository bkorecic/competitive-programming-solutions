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
  map <ll, int> prefix;
  ll sum = 0;
  ll ans = 0;
  prefix[0] = 1;
  for(int i=0; i<n; i++){
    int cur; cin >> cur;
    sum += cur;
    ans += prefix[sum-x];
    prefix[sum]++;
  }
  cout << ans << '\n';
  return 0;
}
