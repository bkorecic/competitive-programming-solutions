#include <bits/stdc++.h>
#define f first
#define s second
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;

ll lcm(ll a, ll b){
    return (a/__gcd(a,b))*b;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    vector <ll> nums(n);
    for(int i=0; i<n; i++) cin >> nums[i];
    sort(nums.begin(), nums.end(), greater<ll>());
    vector <ll> gcd_rac(n);
    gcd_rac[n-1] = nums[n-1];
    for(int i=n-2; i>=0; i--){
        gcd_rac[i] = __gcd(gcd_rac[i+1], nums[i]);
    }
    ll ans = 0;
    for(int i=0; i<n-1; i++){
        ans = __gcd(ans, lcm(nums[i],gcd_rac[i+1]));
    }
    cout << ans << '\n';
    return 0;
}
