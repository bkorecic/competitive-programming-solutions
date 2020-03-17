#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    vector <int> f(5,0);
    int tmp;
    for(int i=0; i<n; i++){
        cin >> tmp;
        f[tmp]++;
    }
    int ans = 0;
    // pair 1-3
    tmp = min(f[1], f[3]);
    f[1] -= tmp; f[3] -= tmp; ans += tmp;

    // convert 1->2
    f[2] += f[1]/2;
    f[1] %= 2;
    
    // convert 2->4
    f[4] += f[2]/2;
    f[2] %= 2;

    // add 3 and 4
    ans += f[3] + f[4];

    // add remaining
    if(f[1] > 0 || f[2] > 0) ans++;
    cout << ans << '\n';
}
