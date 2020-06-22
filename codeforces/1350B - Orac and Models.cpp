#include <bits/stdc++.h>
#define f first
#define s second
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;

vector <ll> nums;
int ans = 0;
int n;

void backtrack(int i, int depth=1){
    //cout << i << ' ' << depth << endl;
    ans = max(ans, depth);
    for(int j=2*i; j<=n; j+=i){
        if(nums[j]>nums[i]){
            backtrack(j, depth+1);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while(t--){
        cin >> n;
        ans = 0;
        nums.resize(n+1);
        for(int i=1; i<=n; i++) cin >> nums[i];
        for(int i=1; i<=n; i++) backtrack(i);
        cout << ans << '\n';
    }


    return 0;
}
