#include <bits/stdc++.h>
#define f first
#define s second
 
using namespace std;
 
typedef long long ll;
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while(t--){
        string a, b, c; cin >> a >> b >> c;
        int n = a.size();
        bool can = true;
        for(int i=0; i<n; i++){
            if(!(c[i] == a[i] || c[i] == b[i])){
                can = false;
                break;
            }
        }
        if(can) cout << "YES\n";
        else cout << "NO\n";
    }
 
    return 0;
}
