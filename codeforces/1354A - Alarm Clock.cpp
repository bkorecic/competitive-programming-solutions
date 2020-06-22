#include <bits/stdc++.h>
#define f first
#define s second
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;

void solve(){
    ll a, b, c, d; cin >> a >> b >> c >> d;
    if(b>=a){
        cout << b << '\n';
        return;
    }
    if(d >= c){
        cout << -1 << '\n';
        return;
    }
    a -= b;
    ll cycle = c-d;
    ll req;
    if(a % cycle == 0) req = a/cycle;
    else req = a/cycle + 1;
    cout << b + req*c << '\n';
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while(t--) solve();

    return 0;
}
