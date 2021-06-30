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
  ll sum = 0;
  for(int i=0; i<n-1; i++){
    ll tmp; cin >> tmp;
    sum += tmp;
  }
  cout << n*(n+1)/2 - sum << '\n';
  return 0;
}
