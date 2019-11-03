#include <bits/stdc++.h>
#define f first
#define s second

using namespace std;

typedef long long ll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    string s; cin >> s;
    int n = s.length() + 1;
    vector <ll> nums(n, 0);
    for(int i=n-2; i>=0; i--){
        if(s[i] == '>'){
            nums[i] = nums[i+1] + 1;
        }
    }
    ll last = nums[0];
    ll ans = last;
    //cout << "i = " << 0 << " ans = " << ans << '\n';
    for(int i=1; i<n; i++){
        if(i == n-1){
            if(s[i-1] == '>'){
                ans += 0;
            }
            else{
                ans += last+1;
            }
        }
        else if(s[i] == '>'){
            if(s[i-1] == '<'){ 
                ans += max(nums[i], last+1);
                last = max(nums[i], last+1);
            }
            else{
                ans += nums[i];
                last = nums[i];
            }
        }
        else{
            if(s[i-1] == '>'){
                ans += 0;
                last = 0;
            }
            else{
                ans += last+1;
                last++;
            }
        }
        //cout << "i = " << i << " ans = " << ans << '\n';
    }
    cout << ans << '\n';
    return 0;
}
