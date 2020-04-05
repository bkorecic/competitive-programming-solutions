#include <bits/stdc++.h>
#define f first
#define s second
#define mp make_pair

using namespace std;

typedef long long ll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    int testcase = 1;
    while(t--){
        int n; cin >> n;
        vector <vector <int>> m(n, vector<int>(n));
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                cin >> m[i][j];
            }
        }
        int trace = 0;
        int row = 0, col = 0;
        // calc trace
        for(int i=0; i<n; i++){
            trace += m[i][i];
        }
        // count rows
        for(int i=0; i<n; i++){
            vector <int> freq(n,0);
            for(int j=0; j<n; j++){
                freq[m[i][j]-1]++;
                if(freq[m[i][j]-1] > 1){
                    row++; break;
                }
            }
        }
        // count cols
        for(int j=0; j<n; j++){
            vector <int> freq(n,0);
            for(int i=0; i<n; i++){
                freq[m[i][j]-1]++;
                if(freq[m[i][j]-1] > 1){
                    col++; break;
                }
            }
        }
        cout << "Case #" << testcase++ << ": " << trace << ' ' << row << ' ' << col << '\n';
        
    }

    return 0;
}
