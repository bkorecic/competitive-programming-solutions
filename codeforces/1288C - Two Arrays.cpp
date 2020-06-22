#include <bits/stdc++.h>
#define f first
#define s second
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m; cin >> n >> m;

    vector<vector<int>> dp(2*m, vector<int>(n+1, -1));
    ll mod = 1e9+7;
    for(int i=1; i<=n; i++){
        dp[2*m-1][i] = 1;
    }
    for(int i=2*m-2; i>=0; i--){
        for(int j=1; j<=n; j++){
            ll sum = 0;
            for(int k=j; k<=n; k++){
                sum = (sum + dp[i+1][k])%mod;
            }
            dp[i][j] = sum;
        }
    }
    ll ans = 0;
    for(int k=1; k<=n; k++){
        ans = (ans+dp[0][k])%mod;
    }
    cout << ans << '\n';
    return 0;
}
