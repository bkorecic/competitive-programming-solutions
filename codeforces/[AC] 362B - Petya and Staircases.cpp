#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second
#define mp make_pair
#define pb push_back

typedef long long ll;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, m;
	cin >> n >> m;
	if(m == 0){
		cout << "YES\n";
		return 0;
	}
	vector <int> nums(m);
	for(int i=0; i<m; i++) cin >> nums[i];
	sort(nums.begin(), nums.end());
	if(nums[0] == 1 || nums[m-1] == n){
		cout << "NO\n";
		return 0;
	}
	for(int i=2; i<m; i++){
		if(nums[i] == nums[i-1] + 1 and nums[i] == nums[i-2] + 2){
			cout << "NO\n";
			return 0;
		}
	}
	cout << "YES\n";
	return 0;
}