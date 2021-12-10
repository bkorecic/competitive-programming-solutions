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
  vector <vector<int>> grid;
  string line;
  while(cin >> line){
    vector <int> row;
    for(char c : line){
      row.push_back(c-'0');
    }
    grid.push_back(row);
  }
  int n = grid.size(), m = grid[0].size();
  int dirx[4] = {1, -1, 0, 0};
  int diry[4] = {0, 0, 1, -1};
  /* part1
  int ans=0;
  for(int x=0; x<n; x++){
    for(int y=0; y<m; y++){
      bool low_p = true;
      for(int d=0; d<4; d++){
        int nx = x+dirx[d];
        int ny = y+diry[d];
        if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
        if(grid[x][y] >= grid[nx][ny]) low_p = false;
      }
      if(low_p) ans += grid[x][y]+1;
    }
  }
  cout << ans << '\n';
  */
  // part2
  vector <int> b_sizes;
  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      if(grid[i][j]!= 9 && grid[i][j] != -1){
        int sz=1;
        queue <pair <int, int>> q;
        grid[i][j] = -1;
        q.push({i, j});
        while(!q.empty()){
          auto [x, y] = q.front();
          q.pop();
          for(int d=0; d<4; d++){
            int nx = x+dirx[d];
            int ny = y+diry[d];
            if(nx < 0 || ny < 0 || nx >= n || ny >= m || grid[nx][ny] == -1 || grid[nx][ny] == 9) continue;
            grid[nx][ny] = -1;
            sz++;
            q.push({nx, ny});
          }
        }
        b_sizes.push_back(sz);
      }
    }
  }
  sort(b_sizes.begin(), b_sizes.end(), greater<int>());
  cout << b_sizes[0]*b_sizes[1]*b_sizes[2] << '\n';
  return 0;
}
