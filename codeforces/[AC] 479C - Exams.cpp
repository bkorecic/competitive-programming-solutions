#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	vector <pair <int,int>> nums(n);
	for(int i=0; i<n; i++){
		cin >> nums[i].f >> nums[i].s;
	}
	sort(nums.begin(), nums.end());
	int cd = nums[0].s;
	for(int i=1; i<n; i++){
		if(nums[i].s >= cd){
			cd = nums[i].s;
		}
		else{
			cd = nums[i].f;
		}
	}
	cout << cd << '\n';
	
	return 0;
}
