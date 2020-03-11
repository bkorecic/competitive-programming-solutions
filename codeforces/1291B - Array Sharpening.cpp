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
        for(int i=0; i<n; i++) cin >> nums[i];
        vector <bool> left(n,false), right(n,false);
        for(int i=0; i<n; i++){
            if(nums[i] >= i) left[i] = true;
            else break;
        }
        for(int i=n-1; i>=0; i--){
            if(nums[i] >= (n-1-i)) right[i] = true;
            else break;
        }
        bool can = false;
        for(int i=0; i<n; i++){
            if((i==0 || left[i-1] == true) && (i==n-1 || right[i+1] == true)
                && (nums[i] > i-1 && nums[i] > (n-1-(i+1)))){
                    can = true;
                    break;
                }
        }
        if(can) cout << "Yes\n";
        else cout << "No\n";
    }
 
    return 0;
}

