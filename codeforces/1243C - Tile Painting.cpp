#include <bits/stdc++.h>
#define f first
#define s second
 
using namespace std;
 
typedef long long ll;
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll n; cin >> n;
    bool prime = true;
    ll g = 0;
    for(ll i = 2; i*i <= n; i++){
        if(n%i == 0){
            prime = false;
            g = __gcd(g, i);
            if(i*i < n){
                g = __gcd(g, n/i);
            }
        }
    }
    if(prime) cout << n << '\n';
    else cout << g << '\n';
    return 0;
}
