#include <bits/stdc++.h>
#define f first
#define s second
 
using namespace std;
 
typedef long long ll;
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    int MAX_NUM = 1e6+1;
    vector <int> nums(n);
    vector <int> ans;
    for(int i=0; i<n; i++) cin >> nums[i];
    vector <bool> in(MAX_NUM, false);
    int days = 0;
    int cur_in = 0;
    bool can = true;
    int timestamp = 0;
    vector <int> in_out(MAX_NUM, -1);
    for(int i=0; i<n; i++){
        if(nums[i] > 0){
            if(in[nums[i]] == true || in_out[nums[i]] == timestamp){
                can = false;
                break;
            }
            in[nums[i]] = true;
            cur_in++;
        }
        else{
            if(in[-nums[i]] == false){
                can = false;
                break;
            }
            in[-nums[i]] = false;
            in_out[-nums[i]] = timestamp;
            cur_in--;
        }
        days++;
 
        if(cur_in == 0){
            ans.push_back(days);
            days = 0;
            timestamp++;
        }
    }
    if(!can || ans.size() == 0 || n%2 == 1 || cur_in != 0){
        cout << -1 << '\n';
        return 0;
    }
    cout << ans.size() << '\n';
    for(int i=0; i<ans.size(); i++){
        if(i) cout << ' ';
        cout << ans[i];
    } cout << '\n';
    return 0;
}
