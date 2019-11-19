#include <bits/stdc++.h>
#define f first
#define s second
 
using namespace std;
 
typedef long long ll;
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while(t--){
        ll a, b;
        cin >> a >> b;
        ll dif = abs(a-b);
        int ans = 0;
        ans += dif/5;
        dif %= 5;
        ans += dif/2;
        dif %= 2;
        ans += dif/1;
        dif %= 1;
        cout << ans << '\n';
    }
    return 0;
}
