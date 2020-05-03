#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector <ll> a(n), b(n);
        for(int i=0; i<n; i++) cin >> a[i];
        for(int i=0; i<n; i++) cin >> b[i];
        
        int firstplus = -1, firstminus = -1;
        for(int i=0; i<n; i++){
            if(a[i] == 1 && firstplus == -1){
                firstplus = i;
            }
            else if(a[i] == -1 && firstminus == -1){
                firstminus = i;
            }
        }
        bool can = true;
        for(int i=n-1; i>=0; i--){
            if(a[i] < b[i]){
                if(firstplus >= i || firstplus == -1){
                    can = false;
                    break;
                }
            }
            if(a[i] > b[i]){
                if(firstminus >= i || firstminus == -1){
                    can = false;
                    break;
                }
            }
        }
        if(can) cout << "YES\n";
        else cout << "NO\n";
    }
    
    return 0;
}