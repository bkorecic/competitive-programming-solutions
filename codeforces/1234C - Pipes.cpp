#include <bits/stdc++.h>
#define f first
#define s second
 
using namespace std;
 
typedef long long ll;
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int q; cin >> q;
    while(q--){
        int n; cin >> n;
        vector <vector<int>> grid(2, vector<int>(n));
        for(int i=0; i<2; i++){
            for(int j=0; j<n; j++){
                char in; cin >> in;
                int new_num = (in - '0');
                if(new_num <= 2) new_num = 0;
                else new_num = 1;
                grid[i][j] = new_num;
            }
        } 
        int i = 0, j = 0;
        int from = 0; //0 si se llega horizontal, 1 si vertical
        while(true){
            if(j > n-1) break;
            if(grid[i][j] == 0 && from == 1){
                break;
            }
            if(grid[i][j] == 0 && from == 0){
                j++;
                from = 0;
            }
            else if(grid[i][j] == 1 && from == 0){
                i = 1-i;
                from = 1;
            }
            else if(grid[i][j] == 1 && from == 1){
                j++;
                from = 0;
            } 
        }
        if(i == 1 && j == n) cout << "YES\n";
        else cout << "NO\n";
    }
    
    return 0;
}
