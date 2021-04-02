#include <bits/stdc++.h>
#define f first
#define s second
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;

void solve(){
  int n; cin >> n;
  vector <pair <int,int>> schedule(n);
  vector <int> tm(n);
  for(int i=0; i<n; i++){
    cin >> schedule[i].f >> schedule[i].s;
  }
  for(int i=0; i<n; i++) cin >> tm[i];
  int t = 0;
  for(int i=0; i<n; i++){
    if(i == 0){
      t = schedule[0].f + tm[0];
      //cout << i << ": " << t << endl;
    }
    else{
      int tmin = (schedule[i-1].s - schedule[i-1].f + 1)/2;
      int departure = max(schedule[i-1].s, t + tmin);
      //cout << i << ": " << schedule[i-1].s << ' ' << t+tmin;
      t = departure + (schedule[i].f - schedule[i-1].s + tm[i]);
      //cout << ' ' << t << endl;
      //cout << "\tdeparture: " << departure << endl;
    }
    if(i == n-1){
      cout << t << endl;
      return;
    }
  }
  
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  int t; cin >> t;
  while(t--) solve();
  

  return 0;
}

