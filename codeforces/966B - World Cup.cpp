#include <bits/stdc++.h>
#define f first
#define s second
#define mp make_pair
#define pb push_back

typedef long long ll;

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    vector <ll> nums(n);
    for(int i=0; i<n; i++){
        cin >> nums[i];
    }
    vector <ll> tm(n);
    for(int i=0; i<n; i++){
        ll x = (nums[i]-i)/n;
        if(x*n < nums[i]-i) x++;
        tm[i] = i+x*n;
    }
    int ans = -1;
    ll anst = 1e18;
    for(int i=0; i<n; i++){
        if(tm[i] < anst){
            anst = tm[i];
            ans = i;
        }
    }
    cout << ans+1 << '\n';
    return 0;
}
