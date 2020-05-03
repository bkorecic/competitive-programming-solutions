#include <bits/stdc++.h>
#define f first
#define s second
#define pb push_back
#define mp make_pair
 
using namespace std;
 
typedef long long ll;
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector <int> nums(n);
        for(int i=0; i<n; i++) cin >> nums[i];
        bool can = true;
        for(int i=0; i<n-1; i++){
            if(nums[i+1] > nums[i] && nums[i+1] != nums[i]+1) can = false;
        }
        if(can) cout << "Yes\n";
        else cout << "No\n";
 
    }
    
    return 0;
}