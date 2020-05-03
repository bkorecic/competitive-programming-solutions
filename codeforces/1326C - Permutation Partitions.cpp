#include <bits/stdc++.h>
#define f first
#define s second
 
using namespace std;
 
typedef long long ll;
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, k; cin >> n >> k;
    int low = n-k+1;
    vector <ll> index;
    for(int i=0; i<n; i++){
        int aux; cin >> aux;
        if(aux >= low){
            index.push_back(i);
        }
    }
    sort(index.begin(), index.end());
    ll a = 0;
    for(int i=low; i<=n; i++) a+=i;
    cout << a << ' ';
    ll ans = 1;
    ll MOD = 998244353;
    for(int i=0; i<k-1; i++){
        ans = (ans*(index[i+1]-index[i]))%MOD;
    }
    cout << ans << '\n';
 
    return 0;
}