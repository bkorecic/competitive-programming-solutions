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
        vector <int> nums(n);
        for(int i=0; i<n; i++) cin >> nums[i];
        sort(nums.begin(), nums.end(), greater<int>());
        int ans = 0;
        for(int i=0; i<n; i++){
            ans = max(ans, min(i+1, nums[i])); 
        }
        cout << ans << '\n';
    } 
    return 0;
}
