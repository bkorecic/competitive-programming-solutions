#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	vector <int> nums(n);
	for(int i=0; i<n; i++)cin >> nums[i];
	int cmax = nums[0], ans = 1;
	for(int i=0; i<n; i++){
		if(i+1 > cmax)ans++;
		if(nums[i] > cmax)cmax = nums[i];
	}
	cout << ans << '\n';
	return 0;
}