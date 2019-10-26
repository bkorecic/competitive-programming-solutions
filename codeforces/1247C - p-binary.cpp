#include <bits/stdc++.h>
#define f first
#define s second
 
using namespace std;
 
typedef long long ll;
 
int set_bits(ll x){
    int ans = 0;
    while(x){
        ans += x & 1; 
        x >>= 1;
    }
    return ans; 
}
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll n; int p;
    cin >> n >> p;
    for(int i=1; i<=50; i++){
        ll test = n - i*p;
        if(test <= 0) break;
        if(set_bits(test) <= i && i <= test){
            cout << i << '\n';
            return 0;
        }
    }
    cout << -1 << '\n';
    return 0;
}
