#include <bits/stdc++.h>
#define f first
#define s second
 
using namespace std;
 
typedef long long ll;
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector <ll> nums(n);
        ll total_sum = 0;
        for(int i=0; i<n; i++){
            cin >> nums[i];
            total_sum += nums[i];
        }
        //kadane from 0 to n-1
        vector <ll> dp(n-1);
        dp[0] = nums[0];
        ll ans = dp[0];
        for(int i=1; i<n-1; i++){
            dp[i] = max(dp[i-1], 0LL) + nums[i];
            ans = max(ans, dp[i]);
        }
        //check segments ending in last element
        ll sum = nums[n-1];
        ans = max(ans, sum);
        for(int i=n-2; i>=1; i--){
            sum += nums[i];
            ans = max(ans, sum);
        }
 
        if(ans >= total_sum){
            cout << "NO\n";
        }
        else{
            cout << "YES\n";
        }
    }
 
    return 0;
}
