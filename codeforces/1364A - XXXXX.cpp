#include <bits/stdc++.h>
#define f first
#define s second
#define pb push_back
#define mp make_pair

typedef long long ll;

using namespace std;

void solve(){
    int n, x; cin >> n >> x;
    vector <ll> nums(n);
    ll sum = 0;
    for(int i=0; i<n; i++){
        cin >> nums[i];
        sum += nums[i];
    }
    if(sum%x == 0){
        int left = 0, right = 0;
        ll sum_aux = 0;
        for(int i=0; i<n; i++){
            sum_aux += nums[i];
            left++;
            if(sum_aux%x != 0){
                break;
            }
        }
        sum_aux = 0;
        for(int i=n-1; i>=0; i--){
            sum_aux += nums[i];
            right++;
            if(sum_aux%x != 0){
                break;
            }
        }
        if(left == n || right == n) cout << -1 << '\n';
        else cout << n-min(left,right) << '\n';
    }
    else{
        cout << n << '\n';
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}
