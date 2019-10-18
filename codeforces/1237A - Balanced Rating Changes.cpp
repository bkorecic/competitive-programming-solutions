#include <bits/stdc++.h>
#define f first
#define s second
 
using namespace std;
 
typedef long long ll;
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    int total = 0;
    vector <int> nums(n);
    for(int i=0; i<n; i++){
        cin >> nums[i]; 
        total += nums[i]/2;
    }
    if(total < 0){
        for(int i=0; i<n; i++){
            if(nums[i]%2 == 1 && nums[i] > 0){
                nums[i]++;
                total++;
                if(total == 0) break;
            }
        }
    }
    else if(total > 0){
        for(int i=0; i<n; i++){
            if(abs(nums[i])%2 == 1 && nums[i] < 0){
                nums[i]--;
                total--;
                if(total == 0) break;
            }
        }
    }
    for(int i=0; i<n; i++){
        cout << nums[i]/2 << '\n';
    }
    return 0;
}
