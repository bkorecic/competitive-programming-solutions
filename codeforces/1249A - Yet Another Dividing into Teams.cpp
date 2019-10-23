#include <bits/stdc++.h>
#define f first
#define s second
 
using namespace std;
 
typedef long long ll;
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int q; cin >> q;
    while(q--){
        int n; cin >> n;
        vector <int> nums(n);
        for(int i=0; i<n; i++) cin >> nums[i];
        sort(nums.begin(), nums.end());
        int ans = 1;
        for(int i=1; i<n; i++){
            if(nums[i] - nums[i-1] == 1) ans = 2;
        }
        cout << ans << '\n';
    }
    return 0;
}