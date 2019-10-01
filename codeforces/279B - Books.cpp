#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second
#define mp make_pair
#define pb push_back

typedef long long ll;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, t; cin >> n >> t;
	vector <int> nums(n);
	vector <int> sums(n);
	for(int i=0; i<n; i++) cin >> nums[i];
	sums[0] = nums[0];
	for(int i=1; i<n; i++){
		sums[i] = sums[i-1] + nums[i];
	}
	int ans = -1;
	for(int i=0; i<n; i++){
		int l = i, r = n-1, mid;
		int restar, testear;
		while(l < r){
			mid = (l+r)/2;
			restar = i > 0 ? sums[i-1] : 0;
			testear = sums[mid] - restar;
			if(testear >= t){
				r = mid;
			}
			else{
				l = mid+1;
			}
		}
		testear = sums[l] - restar;
		//cout << "en i = " << i << "\tans =" << ans << "\tl-i = " << l-i << endl;
		if(testear <= t) ans = max(ans, l-i+1);
		else ans = max(ans, l-i);
	}
	cout << ans << '\n';
	
	
	return 0;
}