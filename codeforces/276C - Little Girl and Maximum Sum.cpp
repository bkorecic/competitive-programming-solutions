#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, q; cin >> n >> q;
    vector <ll> nums(n);
    for(int i=0; i<n; i++) cin >> nums[i];
    vector <ll> dif(n, 0); // dif will hold number of times each index is summed
    for(int i=0; i<q; i++){
        int l, r; cin >> l >> r;
        l--; r--;
        dif[l]++;
        if(r != n-1) dif[r+1]--;
    }
    for(int i=1; i<n; i++){
        dif[i] = dif[i-1] + dif[i];
    }
    sort(dif.begin(), dif.end(), greater<int>());
    sort(nums.begin(), nums.end(), greater<int>());
    ll ans = 0;
    for(int i=0; i<n; i++){
        ans += nums[i]*dif[i];
    }
    cout << ans << '\n';
    return 0;
}
