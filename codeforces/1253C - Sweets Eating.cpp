#include <bits/stdc++.h>
#define f first
#define s second
 
using namespace std;
 
typedef long long ll;
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m; cin >> n >> m;
    vector <ll> nums(n);
    for(int i=0; i<n; i++) cin >> nums[i];
    sort(nums.begin(), nums.end());
    vector <ll> suma(m, 0);
    ll ans = 0;
    for(int i=0; i<n; i++){
        ans += nums[i];
        if(i>=m) ans += suma[i%m];
        suma[i%m] += nums[i];
        if(i) cout << ' ';
        cout << ans;
    } cout << '\n';
    return 0;
}
