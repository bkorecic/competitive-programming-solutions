#include <bits/stdc++.h>

using namespace std;

vector <vector <char>> grid;
vector <vector <bool>> visited;
int n, m, k, s;
int cur;

int dirx[4] = {1, -1, 0, 0};
int diry[4] = {0, 0, 1, -1};

void dfs(int i, int j){
    if(cur == s-k) return;
    visited[i][j] = true;
    cur++;
    for(int dir=0; dir<4; dir++){
        int new_i = i+dirx[dir];
        int new_j = j+diry[dir];
        if(new_i < 0 || new_j < 0 || new_i >= n || new_j >= m) continue;
        if(grid[new_i][new_j] == '#') continue;
        if(!visited[new_i][new_j]) dfs(new_i, new_j);
    } 
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m >> k;
    grid.resize(n, vector<char>(m));
    visited.assign(n, vector<bool>(m, false));
    int x, y;
    s = 0; cur = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> grid[i][j];
            if(grid[i][j] == '.'){
                x = i; y = j;
                s++;
            }
        }
    }
    dfs(x, y);
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(!visited[i][j] && grid[i][j] == '.') grid[i][j] = 'X';
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout << grid[i][j];
        } cout << '\n';
    }
    return 0;
}
