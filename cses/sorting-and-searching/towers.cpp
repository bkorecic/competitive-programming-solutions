#include <bits/stdc++.h>
#define f first
#define s second
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n; cin >> n;
  multiset <int> s;
  int ans = 0;
  for(int i=0; i<n; i++){
    int cur; cin >> cur;
    auto it = s.upper_bound(cur);
    if(it != s.end()){
      s.erase(it);
      s.insert(cur);
    }
    else{
      ans++;
      s.insert(cur);
    }
  }
  cout << ans << '\n';
  return 0;
}
