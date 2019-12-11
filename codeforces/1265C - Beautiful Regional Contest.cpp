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
        int mid = n/2 - 1;
        while(mid > 0 && nums[mid] == nums[mid+1]) mid--;
        int g=0, s=0, b=0;
        int first_s;
        for(int i=0; i<=mid; i++){
            if(nums[i] != nums[i+1]){
                first_s = i+1; 
                g = i+1;
                break;
            }
        }
        //cout << "mid = " << mid << '\n';
        //cout << "found g = " << g << '\n';
        for(int i=first_s; i<=mid; i++){
            if(nums[i] != nums[i+1] && i-first_s+1 > g){
                s = i-first_s+1;
                b = (mid+1) - g - s;
                break;
            }
        }
        //cout << "found s, b = " << s << ' ' << b << '\n';
        bool can = true;
        if(g >= s || g >= b) can = false;
        if(g <= 0 || s <= 0 || b <= 0) can = false;
        if(mid <= 0) can = false;
        if(can) cout << g << ' ' << s << ' ' << b << '\n';
        else cout << "0 0 0\n";
    }
    return 0;
}
