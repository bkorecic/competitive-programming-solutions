#include <bits/stdc++.h>
#define f first
#define s second
 
using namespace std;
 
typedef long long ll;
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while(t--){
        ll n, g, b; cin >> n >> g >> b;
        ll half = (n+n%2)/2;
        ll k = half/g;
        if(k==0) cout << n << '\n';
        else if(half%g == 0){
            cout << g*k + max(b*(k-1), n-half) << '\n';
        }
        else{
            cout << g*k + half%g + max(b*k, n-half) << '\n';
        }
    }
    return 0;
}
