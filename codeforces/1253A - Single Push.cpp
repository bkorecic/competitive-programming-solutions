#include <bits/stdc++.h>
#define f first
#define s second
 
using namespace std;
 
typedef long long ll;
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector <int> a(n);
        vector <int> b(n);
        for(int i=0; i<n; i++) cin >> a[i];
        for(int i=0; i<n; i++) cin >> b[i];
        vector <int> resta(n);
        for(int i=0; i<n; i++) resta[i] = b[i] - a[i];
        int dif = 1e6;
        bool can = true;
        bool fnd = false;
        for(int i=0; i<n; i++){
            if(i>0 && resta[i] == 0 && resta[i-1] != 0) fnd = true;
            if(resta[i] != 0){
                if(resta[i] < 0) can = false;
                if(dif != 1e6 && resta[i] != dif) can = false;
                dif = resta[i];
            }
            if(resta[i] != 0 && fnd) can = false; 
        }
        if(can) cout << "YES\n";
        else cout << "NO\n";
    }
 
    return 0;
}

