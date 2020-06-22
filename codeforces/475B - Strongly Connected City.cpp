#include <bits/stdc++.h>
#define f first
#define s second
#define mp make_pair
#define pb push_back
 
using namespace std;
 
typedef long long ll;
 
vector <vector<bool>> visited;
int n, m;
string h, v;
 
void dfs(int i, int j){
    visited[i][j] = true;
    //cout << "visiting " << i << ' ' << j << endl;
 
    int movex, movey;
    if(h[j] == '>') movex = 1;
    else movex = -1;
 
    if(v[i] == '^') movey = -1;
    else movey = 1;
 
    if(j+movey >= 0 && j+movey < m && !visited[i][j+movey]){
        dfs(i, j+movey);    
    }
    if(i+movex >= 0 && i+movex < n && !visited[i+movex][j]){
        dfs(i+movex, j); 
    }
}
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> m >> n;
    cin >> h >> v;
 
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            visited.assign(n, vector<bool>(m, false));
            dfs(i, j);
            for(int x=0; x<n; x++){
                for(int y=0; y<m; y++){
                    if(visited[x][y] == false){
                        cout << "NO\n";
                        //cout << i << ' ' << j << endl;
                        //cout << x << ' ' << y << endl;
                        return 0;
                    }
                }
            }
        }
    }
    cout << "YES\n";
    return 0;
}
