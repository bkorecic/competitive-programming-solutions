#include <bits/stdc++.h>
#define f first
#define s second
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  int t; cin >> t;
  while(t--){
    ll x, y; cin >> x >> y;
    ll m = max(x, y);
    ll mid = 1+m*(m-1);
    if(m%2 == 0){
      cout << mid + x-y << '\n';
    }
    else{
      cout << mid + y-x << '\n';
    }
  }
  

  return 0;
}
