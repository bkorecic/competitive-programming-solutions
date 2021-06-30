#include <bits/stdc++.h>
#define f first
#define s second
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  ll n; cin >> n;
  // n! = 2^a 5^b .....
  ll a = 0;
  ll b = 0;
  for(ll i=2; i<=n; i*=2){
    a += n/i;
  }
  for(ll i=5; i<=n; i*=5){
    b += n/i;
  }
  cout << min(a, b) << '\n';
  return 0;
}
