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
  while(n != 1){
    cout << n << ' ';
    if(n%2==0) n/=2;
    else n=3*n+1;
  }
  cout << "1\n";
  return 0;
}
