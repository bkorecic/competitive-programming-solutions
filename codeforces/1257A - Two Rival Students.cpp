#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while(t--){
        int n, x, a, b;
        cin >> n >> x >> a >> b;
        if(a>b) swap(a,b);
        int ans = b - a;
        ans += min(n-b, x);
        x -= min(n-b, x);
        ans += min(a-1, x);
        cout << ans << '\n';
    }
    return 0;
}