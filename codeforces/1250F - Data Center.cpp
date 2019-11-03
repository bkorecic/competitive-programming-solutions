#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    int ans = 1e8;
    for(int i=1; i*i <= n; i++){
        if(n%i == 0){
            ans = min(ans, 2*i + 2*(n/i));
        }
    }
    cout << ans << '\n';
    return 0;
}