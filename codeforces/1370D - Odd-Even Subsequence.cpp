#include <bits/stdc++.h>
#define f first
#define s second
#define mp make_pair
#define pb push_back

typedef long long ll;

using namespace std;

int n, k;
vector <int> nums;

bool try_(int mid){
    int added_even = 0;
    int added_odd = 0;
    for(int i=0; i<n; i++){
        if(nums[i] <= mid){
            if(k%2==1 or i<n-1) added_even++;
            i++;
        }
    }
    for(int i=1; i<n; i++){
        if(nums[i] <= mid){
            if(k%2==0 or i<n-1) added_odd++;
            i++;
        }
    }
    return added_even >= k/2+(k%2==1) or added_odd >= k/2;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> k;
    nums.resize(n);
    for(int i=0; i<n; i++) cin >> nums[i];
    int l=1, r=1e9, mid;
    while(l<r){
        mid = l + (r-l)/2;
        if(try_(mid)) r = mid;
        else l = mid+1;
    }
    cout << l << '\n';
    return 0;
}
