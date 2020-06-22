#include <bits/stdc++.h>
#define f first
#define s second
#define pb push_back
#define mp make_pair

typedef long long ll;

using namespace std;

void solve(){
    int n; cin >> n;
    vector <int> nums(n);
    for(int i=0; i<n; i++) cin >> nums[i];
    vector <int> indices = {0};
    for(int i=1; i<n-1; i++){
        if(nums[i] < nums[i-1] && nums[i] < nums[i+1]) indices.pb(i);
        if(nums[i] > nums[i-1] && nums[i] > nums[i+1]) indices.pb(i);
    }
    indices.pb(n-1);
    int k = indices.size();
    cout << k << '\n';
    for(int i : indices){
        cout << nums[i] << " \n"[i==indices[k-1]];
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while(t--) solve();


    return 0;
}
