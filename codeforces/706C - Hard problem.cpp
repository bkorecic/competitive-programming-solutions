#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll INF = LLONG_MAX;
    int n; cin >> n;
    vector <ll> cost(n);
    vector <string> strings(n);
    vector <string> rstrings(n);
    for(int i=0; i<n; i++) cin >> cost[i];
    for(int i=0; i<n; i++){
        cin >> strings[i];
        rstrings[i] = strings[i];
        reverse(rstrings[i].begin(), rstrings[i].end());
    }

    vector <vector<ll>> dp(n, vector<ll>(2,INF));
    dp[0][0] = 0;
    dp[0][1] = cost[0];
    for(int i=1; i<n; i++){
        if(strings[i-1] <= strings[i] && dp[i-1][0] != INF){
            dp[i][0] = dp[i-1][0];
        }
        if(rstrings[i-1] <= strings[i] && dp[i-1][1] != INF){
            dp[i][0] = min(dp[i][0], dp[i-1][1]);
        }
     
        if(strings[i-1] <= rstrings[i] && dp[i-1][0] != INF){
            dp[i][1] = dp[i-1][0] + cost[i];
        }
        if(rstrings[i-1] <= rstrings[i] && dp[i-1][1] != INF){
            dp[i][1] = min(dp[i][1], dp[i-1][1] + cost[i]);
        }
    }
    ll ans = min(dp[n-1][0], dp[n-1][1]);
    if(ans == INF) cout << -1 << '\n';
    else cout << ans << '\n';
    return 0;
}
