#include <bits/stdc++.h>
#define f first
#define s second
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;

const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, -1, 1};
const char mv[4] = {'D', 'U', 'L', 'R'};
map <char, int> get_move = {{'D', 0}, {'U', 1}, {'L', 2}, {'R', 3}};
bool visited[7][7];
string s;
int ans = 0;

bool is_valid(int x, int y){
  return x >= 0 and y >= 0 and x < 7 and y < 7 and !visited[x][y];
}

void backtrack(int x, int y, char last_move, int i){
  //cout << x << ' ' << y << ' ' << last_move << ' ' << i << endl;
  if(x == 6 and y == 0){
    if(i == 48) ans++;
    return;
  }
  if(last_move == 'D'){
    if(!is_valid(x+1, y) and is_valid(x, y-1) and is_valid(x, y+1)) return;
  }
  else if(last_move == 'U'){
    if(!is_valid(x-1, y) and is_valid(x, y-1) and is_valid(x, y+1)) return;
  }
  else if(last_move == 'L'){
    if(!is_valid(x, y-1) and is_valid(x-1, y) and is_valid(x+1, y)) return;
  }
  else if(last_move == 'R'){
    if(!is_valid(x, y+1) and is_valid(x-1, y) and is_valid(x+1, y)) return;
  }
  if(s[i] == '?'){
    for(int d=0; d<4; d++){
      int nx = x+dx[d];
      int ny = y+dy[d];
      if(!is_valid(nx, ny)) continue;
      visited[nx][ny] = 1;
      backtrack(nx, ny, mv[d], i+1);
      visited[nx][ny] = 0;
    }
  }
  else{
    int d = get_move[s[i]];
    int nx = x+dx[d];
    int ny = y+dy[d];
    //cout << d << " (" << x << ' ' << y << ") -> (" << nx << ' ' << ny << ")" << endl;
    if(!is_valid(nx, ny)) return;
    visited[nx][ny] = 1;
    backtrack(nx, ny, s[i], i+1);
    visited[nx][ny] = 0;
  }
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  cin >> s;
  if(s[0] == 'L' or s[0] == 'U'){
    cout << 0 << '\n';
    return 0;
  }
  visited[0][0] = true;
  backtrack(0, 0, 'X', 0);
  cout << ans << endl;
  return 0;
}
