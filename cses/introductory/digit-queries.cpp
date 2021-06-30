#include <bits/stdc++.h>
#define f first
#define s second
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  vector <ll> pow10(19, 1);
  for(int i=1; i<19; i++){
    pow10[i] = pow10[i-1]*10;
  }
  auto eval = [&](int n){
    return pow10[n]*n - (pow10[n]-1)/9;
  };
  int q; cin >> q;
  while(q--){
    ll k; cin >> k;
    int d = 0;
    for(int i=0; i<18; i++){
      if(eval(i) >= k){
        d = i;
        break;
      }
    }
    ll start = eval(d-1)+1;
    ll block = (k-start)/d;
    cout << to_string(pow10[d-1]+block)[(k-start)%d] << '\n';
  }
  return 0;
}
