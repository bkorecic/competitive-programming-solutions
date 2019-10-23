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
        vector <int> ans(n,-1);
        for(int i=0; i<n; i++){
            cin >> nums[i];
            nums[i]--;
        }
        for(int i=0; i<n; i++){
            if(ans[i] != -1) continue;
            queue <int> fill;
            int cur = nums[i];
            while(cur != i){
                fill.push(cur);
                cur = nums[cur];
            }
            ans[i] = fill.size() + 1;
            while(!fill.empty()){
                int j = fill.front();
                fill.pop();
                ans[j] = ans[i];
            }
        }
        for(int i=0; i<n; i++){
            if(i) cout << ' ';
            cout << ans[i];
        } cout << '\n';
    }
    return 0;
}