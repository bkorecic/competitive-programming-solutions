#include <bits/stdc++.h>
#define f first
#define s second
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;

const ll MOD = 1e9+7;

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n; cin >> n;
  ll ans = 1;
  for(int i=0; i<n; i++){
    ans = (ans*2)%MOD;
  }
  cout << ans << '\n';
  return 0;
}
