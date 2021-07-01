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
  vector <pair<int,bool>> events; // {t, 0} if arrival, {t, 1} if leaving
  for(int i=0; i<n; i++){
    int a, b; cin >> a >> b;
    events.push_back({a, 0});
    events.push_back({b, 1});
  }
  sort(events.begin(), events.end());
  int ans = 0;
  int cur = 0;
  for(auto& [t, type] : events){
    if(type == 0){
      cur++;
      ans = max(ans, cur);
    }
    else{
      cur--;
    }
  }
  cout << ans << '\n';
  return 0;
}
