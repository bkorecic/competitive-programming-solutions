#include <bits/stdc++.h>
#define f first
#define s second
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;

void solve(){
    int n; cin >> n;
    vector <int> nums(n);
    for(int i=0; i<n; i++) cin >> nums[i];
    sort(nums.begin(), nums.end());
    int ans = 0;
    for(int i=0; i<n; i++){
        for(int j=i; j<n; j++){
            if(nums[j] <= j-i+1){
                ans++;
                i=j+1;
            }
        }
    }
    cout << ans << '\n';
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while(t--) solve();
    

    return 0;
}
