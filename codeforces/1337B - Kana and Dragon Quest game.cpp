#include <bits/stdc++.h>
#define f first
#define s second
 
using namespace std;
 
typedef long long ll;
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while(t--){
        int x, n, m; cin >> x >> n >> m;
        for(int i=0; i<n && x > 20; i++){
            x = x/2 + 10;
        }
        x -= 10*m;
        if(x <= 0) cout << "YES\n";
        else cout << "NO\n";
    }
 
    return 0;
}