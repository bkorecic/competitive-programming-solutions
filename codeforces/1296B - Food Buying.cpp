#include <bits/stdc++.h>
#define f first
#define s second
 
using namespace std;
 
typedef long long ll;
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while(t--){
        ll s; cin >> s;
        ll ans = 0;
        while(s>=10){
            ll aux = s;
            aux -= s%10;
            //cout << s << ' ' << aux << endl;
            ans += aux;
            s -= aux;
            s += aux/10;
        }
        cout << ans+s << '\n';
    }
 
    return 0;
}
