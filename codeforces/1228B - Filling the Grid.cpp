#include <bits/stdc++.h>
#define f first
#define s second

using namespace std;

typedef long long ll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int h, w; cin >> h >> w;
    vector <int> r(h);
    vector <int> c(w);
    for(int i=0; i<h; i++) cin >> r[i];
    for(int i=0; i<w; i++) cin >> c[i];
    vector <vector <bool>> grid(h,vector<bool>(w, false));
    for(int i=0; i<h; i++){
        for(int j=0; j<r[i]; j++) grid[i][j] = true;
    }
    for(int j=0; j<w; j++){
        for(int i=0; i<c[j]; i++) grid[i][j] = true;
    }
    // check if valid
    bool valid = true;
    for(int i=0; i<h; i++){
        int j = 0;
        while(j < w && grid[i][j] == true){
            j++; 
        }
        if(j != r[i]) valid = false;
    }
    for(int j=0; j<w; j++){
        int i = 0;
        while(i < h && grid[i][j] == true){
            i++;
        }
        if(i != c[j]) valid = false;
    }
    int q = 0;
    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            if(grid[i][j] == false && j > r[i] && i > c[j]) q++;
        }
    }
    // su j debe ser mayor a r[i]
    // su i debe ser mayor a c[j]
    //cout << "q = " << q << endl;
    ll ans = 1;
    ll MOD = 1e9 + 7;
    for(int i=0; i<q; i++){
        ans = (ans*2) % MOD;
    }
    if(!valid) cout << "0\n";
    else if(q==0) cout << "1\n";
    else cout << ans << '\n';
    return 0;
}
