#include <bits/stdc++.h>
#define f first
#define s second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    vector <int> nums(n);
    for(int i=0; i<n; i++) cin >> nums[i];
    int ans = 0;
    for(int i=1; i<n-1; i++){
        if((nums[i] > nums[i-1] && nums[i] > nums[i+1])
            || (nums[i] < nums[i-1] && nums[i] < nums[i+1])) ans++;
    }
    cout << ans << '\n';
    return 0;
}
