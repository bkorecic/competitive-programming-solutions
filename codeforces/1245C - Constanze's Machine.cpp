#include <bits/stdc++.h>
#define f first
#define s second

using namespace std;

typedef long long ll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll MOD = 1e9+7;
    string s; cin >> s;
    int n = s.length();
    vector <ll> fib(n+1, 0);
    fib[0] = 1;
    fib[1] = 1;
    for(int i=2; i<=n; i++){
        fib[i] = (fib[i-1] + fib[i-2])%MOD;
    }
    ll ans = 1;
    int cnt = 1;
    char cur = s[0];
    s += "0";
    for(int i=1; i<=n; i++){
        //cout << i << ' ' << cnt << ' ' << cur << '\n';
        if(s[i] != cur){
            //cout << "fib[cnt] = " << fib[cnt] << '\n';
            if(cur == 'u' || cur == 'n') ans = (ans*fib[cnt])%MOD; 
            cnt = 1;
        }
        else if(s[i] == cur){
            cnt++;
        }
        cur = s[i];
    }
    for(int i=0; i<n; i++){
        if(s[i] == 'm' || s[i] == 'w') ans = 0;
    }
    cout << ans << '\n';
    return 0;
}
