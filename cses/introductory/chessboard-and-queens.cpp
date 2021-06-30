#include <bits/stdc++.h>
#define f first
#define s second
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  vector <string> grid(8);
  for(int i=0; i<8; i++) cin >> grid[i];
  // filas: [0, 1, 2, 3, 4, 5, 6, 7]
  // columnas: permutar [0, 1, 2, 3, 4, 5, 6, 7]
  int ans = 0;
  vector <int> cols = {0, 1, 2, 3, 4, 5, 6, 7};
  do{
    bool can = true;
    for(int i=0; i<8; i++){
      if(grid[i][cols[i]] == '*') can = false;
    }
    for(int i=0; i<8; i++){
      for(int j=i+1; j<8; j++){
        int x1 = i, y1 = cols[i];
        int x2 = j, y2 = cols[j];
        if(abs(x1-x2) == abs(y1-y2)) can = false;
      }
    }
    ans += can;
  } while(next_permutation(cols.begin(), cols.end()));
  cout << ans << '\n';
  return 0;
}
