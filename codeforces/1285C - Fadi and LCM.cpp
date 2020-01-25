#include <bits/stdc++.h>
#define f first
#define s second
 
using namespace std;
 
typedef long long ll;
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll x; cin >> x;
    vector <ll> div;
    for(ll i=1; i*i<x; i++){
        if(x%i == 0) div.push_back(i);
    }
    if(x==1) div.push_back(1);
    for(ll i=div.size()-1; i>=0; i--){
        ll a = div[i];
        ll b = x/div[i];
        if((a*b)/(__gcd(a,b)) == x){
            cout << div[i] << ' ' << x/div[i] << '\n';
            break;
        }
    }
    return 0;
}
