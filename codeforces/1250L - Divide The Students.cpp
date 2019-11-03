#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while(t--){
        int a, b, c;
        cin >> a >> b >> c;
        if(a<c) swap(a,c);
        int x=a/2 + a%2, y=a/2, z = c;
        while(b--){
            if(x <= y && x <= z){
                x++;
            }
            else if(y <= x && y <= z){
                y++;
            }
            else{
                z++;
            }
        }
        cout << max(x, max(y,z)) << '\n';
    }
    return 0;
}