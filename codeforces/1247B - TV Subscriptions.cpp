#include <bits/stdc++.h>
#define f first
#define s second
 
using namespace std;
 
typedef long long ll;
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while(t--){
        int n, k, d; cin >> n >> k >> d;
        vector <int> nums(n);
        for(int i=0; i<n; i++)cin >> nums[i];
        set <int> cnt;
        vector <int> freq(k+1, 0);
        for(int i=0; i<d; i++){
            cnt.insert(nums[i]); 
            freq[nums[i]]++;
        }
        int ans = cnt.size();
        //cout << ans << endl;
        for(int i=1; i+d-1<n; i++){
            //for(auto x : cnt) cout << x;
            //cout << endl;
            cnt.insert(nums[i+d-1]);
            freq[nums[i+d-1]]++;
            freq[nums[i-1]]--;
            if(freq[nums[i-1]] == 0) cnt.erase(nums[i-1]);
            //cout << "ins, erase " << i+d-1 << ' ' << i-1 << endl;
            ans = min(ans, (int)cnt.size());
        }
        cout << ans << '\n';
    } 
    return 0;
}

