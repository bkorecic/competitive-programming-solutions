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
  map <int, int> pos; // last seen pos
  int ans = 1;
  int l = 0;
  for(int r=0; r<n; r++){
    int cur; cin >> cur;
    int last = -1;
    if(pos.count(cur)) last = pos[cur];
    l = max(l, last+1);
    pos[cur] = r;
    ans = max(ans, r-l+1);
  }
  cout << ans << '\n';
  return 0;
}
