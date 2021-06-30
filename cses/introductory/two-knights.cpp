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
  for(ll k=1; k<=n; k++){
    /*
    int tmp = 48+(k-4)*16+(k-4)*24+(k-4)*(k-4)*8;
    cout << (k*k*(k*k-1)-tmp)/2 << '\n';
    */
    // simplified expression...
    cout << (k*k*(k*k-1) - 8LL*(k-4)*(k-4) - 40LL*(k-4)-48)/2LL << '\n';
  }
  return 0;
}
