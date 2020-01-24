#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while(t--){
        ll x, y; cin >> x >> y;
        if(x >= y){
            cout << "YES\n";
        }
        else{
            if((x <= 3 && y > 3) || x == 1){
                cout << "NO\n";
            }
            else{
                cout << "YES\n";
            }
        }
    }
    return 0;
}