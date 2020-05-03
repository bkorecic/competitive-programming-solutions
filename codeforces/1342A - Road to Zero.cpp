#include <bits/stdc++.h>
#define f first
#define s second
#define pb push_back
#define mp make_pair
 
using namespace std;
 
typedef long long ll;
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while(t--){
        ll x, y; cin >> x >> y;
        ll a, b; cin >> a >> b;
        b = min(b, 2*a);
        ll ans;
        if(x*y > 0){
            x = abs(x); y = abs(y);
            ll mi = min(x,y);
            ans = mi*b + max(x-mi, y-mi)*a;
        }
        else{
            ans = abs(x)*a + abs(y)*a;
        }
        cout << ans << '\n';
    }
    
    return 0;
}