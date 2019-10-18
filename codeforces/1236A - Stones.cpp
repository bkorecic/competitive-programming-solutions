#include <bits/stdc++.h>
#define f first
#define s second
 
using namespace std;
 
typedef long long ll;
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while(t--){
        int a, b, c; cin >> a >> b >> c;
        int ans = 0;
        while(b > 0 && c >= 2){
            b--; c-=2;
            ans += 3;
        }
        while(a > 0 && b >= 2){
            a--; b-=2;
            ans += 3;
        }
        cout << ans << '\n';
    }
    return 0;
}
