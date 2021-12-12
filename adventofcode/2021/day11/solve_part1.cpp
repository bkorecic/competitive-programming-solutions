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
  vector <vector <int>> grid;
  string s;
  while(cin >> s){
    vector <int> row(s.size());
    for(int i=0; i<s.size(); i++){
      row[i] = s[i]-'0';
    }
    grid.push_back(row);
  }
  int n = grid.size();
  int m = grid[0].size();

  int flashes=0;

  const int dirx[] = {1, 1, 1, -1, -1, -1, 0, 0};
  const int diry[] = {0, 1, -1, 0, 1, -1, 1, -1};

  auto step = [&](){
    queue <pair<int,int>> q;
    for(int i=0; i<n; i++){
      for(int j=0; j<m; j++){
        grid[i][j]++;
        if(grid[i][j] == 10){
          flashes++;
          grid[i][j] = 0;
          q.push({i, j});
        }
      }
    }
    while(!q.empty()){
      auto [x, y] = q.front();
      q.pop();
      for(int d=0; d<8; d++){
        int nx = x+dirx[d];
        int ny = y+diry[d];
        if(nx<0 || ny<0 || nx>=n || ny>=m || grid[nx][ny] == 0) continue;
        grid[nx][ny]++;
        if(grid[nx][ny] == 10){
          flashes++;
          grid[nx][ny] = 0;
          q.push({nx, ny});
        }
      }
    }
  };

  const int STEPS = 100;
  for(int i=0; i<STEPS; i++) step();
  cout << flashes << '\n';
  return 0;
}
