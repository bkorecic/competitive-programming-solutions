#include <bits/stdc++.h>
#define f first
#define s second
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;

/*
  remember: precomputation should be done in main
*/
void solve(){
  ll a, b; cin >> a >> b;
  if((a+b)%3==0 and 2*a>=b and (2*a-b)%3 == 0 and 2*b>=a and (2*b-a)%3 == 0){
    ll x = (2*b-a)/3;
    ll y = (2*a-b)/3;
    if(a-x-2*y == 0 and b-y-2*x == 0)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
  else{
    cout << "NO\n";
  }
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  int t; cin >> t;
  while(t--) solve();
  return 0;
}
