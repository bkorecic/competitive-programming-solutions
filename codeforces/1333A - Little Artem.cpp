#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    int t; cin >> t;
    while(t--){
        int n, m; cin >> n >> m;
        vector<vector<char>> ans(n, vector<char>(m,'B'));
        ans[0][0] = 'W';
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cout << ans[i][j];
            } cout << '\n';
        }
    }    
    return 0;
}
