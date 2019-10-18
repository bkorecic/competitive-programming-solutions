#include <bits/stdc++.h>
#define f first
#define s second
 
using namespace std;
 
typedef long long ll;
 
ll MOD = 1e9 + 7;
 
long long binpow(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll n, m; cin >> n >> m;
    ll ans = binpow(2, m);
    ans = (ans + MOD - 1)%MOD;
    cout << binpow(ans,n) << '\n';
 
    return 0;
}
