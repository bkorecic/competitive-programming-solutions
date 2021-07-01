#include <bits/stdc++.h>
#define f first
#define s second
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, m, k; cin >> n >> m >> k;
  vector <int> a(n), b(m);
  for(int i=0; i<n; i++) cin >> a[i];
  for(int j=0; j<m; j++) cin >> b[j];
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  int ans = 0, i = 0, j = 0;
  while(i < n and j < m){
    if(b[j] >= a[i]-k and b[j] <= a[i]+k){
      ans++;
      i++;
      j++;
    }
    else if(b[j] < a[i]-k){
      j++;
    }
    else if(b[j] > a[i]+k){
      i++;
    }
  }
  cout << ans << '\n';
  return 0;
}
