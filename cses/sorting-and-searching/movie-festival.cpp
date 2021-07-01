#include <bits/stdc++.h>
#define f first
#define s second
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;

bool cmp(pair<int,int> a, pair<int,int> b){
  if(a.s != b.s) return a.s < b.s;
  return a.f < b.f;
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n; cin >> n;
  vector <pair<int,int>> events;
  for(int i=0; i<n; i++){
    int a, b; cin >> a >> b;
    events.push_back({a,b});
  }
  sort(events.begin(), events.end(), cmp);
  int ans = 0;
  int tf = -1;
  for(int i=0; i<n; i++){
    while(i < n and events[i].f < tf) i++;
    if(i < n){
      ans++;
      tf = events[i].s;
    }
  }
  cout << ans << '\n';
  return 0;
}
