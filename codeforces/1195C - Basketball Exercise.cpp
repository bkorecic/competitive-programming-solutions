#include <bits/stdc++.h>
#define f first
#define s second
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    vector <vector<ll>> h(2, vector<ll>(n));
    for(int i=0; i<n; i++) cin >> h[0][i];
    for(int i=0; i<n; i++) cin >> h[1][i];
    vector <vector<ll>> dp(2, vector<ll>(n));
    dp[0][0] = h[0][0];
    dp[1][0] = h[1][0];
    for(int i=1; i<n; i++){
        ll m = 0;
        if(i>1){
            m = max(dp[0][i-2], dp[1][i-2]);
        }
        dp[0][i] = h[0][i] + max(dp[1][i-1], m);
        dp[1][i] = h[1][i] + max(dp[0][i-1], m);
    }
    cout << max(dp[0][n-1], dp[1][n-1]) << '\n';
    return 0;
}
