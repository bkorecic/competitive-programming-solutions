#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector <int> nums(n);
        for(int i=0; i<n; i++) cin >> nums[i];
        vector <int> seen(n+2, -1);
        vector <int> ans(n+2, 1e6);
        seen[nums[0]] = 0;
        for(int i=1; i<n; i++){
            if(seen[nums[i]] != -1){
                ans[nums[i]] = min(ans[nums[i]], i-seen[nums[i]]+1);
            }
            seen[nums[i]] = i;
        }
        int rans = 1e6;
        for(int x : ans){
            rans = min(rans, x);
        }
        if(rans == 1e6) cout << -1 << '\n';
        else cout << rans << '\n'; 
    }
    return 0;
}
