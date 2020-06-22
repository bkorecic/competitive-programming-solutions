#include <bits/stdc++.h>
#define f first
#define s second
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;

int mind(ll a){
    int ans = 10;
    while(a!=0){
        int d = a%10;
        ans = min(ans,d); 
        a/=10;
    }
    return ans;
}

int maxd(ll a){
    int ans = 0;
    while(a!=0){
        int d = a%10;
        ans = max(ans,d);
        a/=10;
    }
    return ans;
}

void solve(){
    ll a, k; cin >> a >> k;
    for(ll i = 0; i<k-1; i++){
        if(mind(a) == 0) break;
        a = a + mind(a)*maxd(a);
    }
    cout << a << '\n'; 
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while(t--)
        solve();
        

    return 0;
}
