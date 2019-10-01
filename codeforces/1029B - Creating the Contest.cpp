#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, ans = 1; cin >> n;
	vector <int> arr(n);
	vector <int> dp(n,1);
	for(int i=0;i<n;i++)cin>>arr[i];
	for(int i=1;i<n;i++){
		if(arr[i] <= 2*arr[i-1]){
			dp[i] = dp[i-1]+1;
			if(dp[i]>ans)ans=dp[i];
		}
	}
	cout << ans << '\n';
	return 0;
}