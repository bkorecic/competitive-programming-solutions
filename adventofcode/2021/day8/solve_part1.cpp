#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "dbg.h"
#else
#define dbg(...) 1313
#endif

typedef long long ll;

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  string s;
  int ans=0;
  set <int> uniq = {2, 3, 4, 7};
  while(cin >> s){
    for(int i=0; i<10; i++) cin >> s;
    for(int i=0; i<4; i++){
      cin >> s;
      if(uniq.count(s.size())) ans++;
    }
  }
  cout << ans << '\n';

  return 0;
}
