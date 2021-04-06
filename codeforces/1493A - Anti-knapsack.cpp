#include <bits/stdc++.h>
#define f first
#define s second
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;

void solve(){
  int n, k; cin >> n >> k;
  int mid = (k+1)/2;
  cout << (n-mid) << '\n';
  for(int i=mid; i<=n; i++){
    if(i == k) continue;
    cout << i << " \n"[i==n];
  }
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  int t; cin >> t;
  while(t--) solve();

  return 0;
}

