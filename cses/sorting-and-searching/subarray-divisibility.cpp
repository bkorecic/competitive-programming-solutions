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
  map <int, int> prefix;
  int sum = 0;
  ll ans = 0;
  prefix[0] = 1;
  for(int i=0; i<n; i++){
    int cur; cin >> cur;
    if(cur < 0){
      cur = n+cur%n;
    }
    sum = (sum+cur%n)%n;
    ans += prefix[sum];
    prefix[sum]++;
  }
  cout << ans << '\n';
  return 0;
}
