#include <bits/stdc++.h>

using namespace std;

int main(){
  vector <vector <int>> m(1001, vector<int>(1001, 0));
  int x1, y1, x2, y2;
  while(scanf("%d,%d -> %d,%d\n", &x1, &y1, &x2, &y2) != EOF){
    int difx = x1 == x2 ? 0 : abs(x2-x1)/(x2-x1);
    int dify = y1 == y2 ? 0 : abs(y2-y1)/(y2-y1);
    // if(x1 != x2 && y1 != y2) continue; // comment for part 2
    for(int x = x1, y = y1; ; x += difx, y += dify){
      m[x][y]++;
      if(x==x2 && y==y2) break;
    }
  }
  int ans=0;
  for(auto v : m) for(auto x : v)
      if(x>1) ans++;
  cout << ans << '\n';
  return 0;
}
