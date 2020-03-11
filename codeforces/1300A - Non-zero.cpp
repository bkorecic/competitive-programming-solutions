#include <bits/stdc++.h>
#define f first
#define s second
 
using namespace std;
 
typedef long long ll;
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while(t--){
        int ans = 0;
        int n; cin >> n;
        vector <int> nums(n);
        for(int i=0; i<n; i++) cin >> nums[i];
        for(int i=0; i<n; i++){
            if(nums[i] == 0){
                nums[i]++;
                ans++;
            }
        }
        int sum = 0;
        for(int i=0; i<n; i++) sum += nums[i];
        if(sum == 0){
            ans++;
        }
        cout << ans << '\n';
    }
 
    return 0;
}
