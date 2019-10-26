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
        int cur = 0;
        vector <int> freq(k+1, 0);
        for(int i=0; i<d; i++){
            if(freq[nums[i]] == 0) cur++;
            freq[nums[i]]++;
        }
        int ans = cur;
        //cout << ans << endl;
        for(int i=1; i+d-1<n; i++){
            //for(auto x : cnt) cout << x;
            //cout << endl;
            if(freq[nums[i+d-1]] == 0) cur++;
            freq[nums[i+d-1]]++;
            freq[nums[i-1]]--;
            if(freq[nums[i-1]] == 0) cur--;
            //cout << "ins, erase " << i+d-1 << ' ' << i-1 << endl;
            ans = min(ans, cur);
        }
        cout << ans << '\n';
    }
    return 0;
}

