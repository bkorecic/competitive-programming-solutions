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
  ll sum = n*(n+1)/2;
  if(sum%2 == 1){
    cout << "NO\n";
    return 0;
  }
  vector <ll> a;
  vector <bool> in_a(n+1, false);
  ll target = sum/2;
  int a_size = 0;
  for(ll i=n; i>=1; i--){
    if(target > i){
      target -= i;
      in_a[i] = true;
      a.push_back(i);
      a_size++;
    }
    else{
      in_a[target] = true;
      a.push_back(target);
      a_size++;
      break;
    }
  }
  vector <ll> b;
  for(int i=1; i<=n; i++){
    if(!in_a[i]) b.push_back(i);
  }
  cout << "YES\n";
  cout << a.size() << '\n';
  for(auto x : a){
    cout << x << ' ';
  } cout << '\n';
  cout << b.size() << '\n';
  for(auto x : b){
    cout << x << ' ';
  } cout << '\n';
  return 0;
}
