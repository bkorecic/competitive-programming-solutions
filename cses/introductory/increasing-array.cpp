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
  ll last; cin >> last;
  ll ans = 0;
  for(int i=0; i<n-1; i++){
    ll cur; cin >> cur;
    if(cur < last){
      ans += last-cur;
    }
    last = max(last, cur);
  }
  cout << ans << '\n';
  return 0;
}
