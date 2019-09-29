#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;

typedef long long ll;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int N, B; 
	while(cin >> N >> B, N != -1){
		vector <int> nums(N);
		for(int i=0; i<N; i++)cin>>nums[i];
		sort(nums.begin(), nums.end(), greater<int>());
		int l = 0, r = nums[0], mid;
		while(l < r){
			mid = (l+r)/2;
			//cout << "\tMID = " << mid << '\t';
			bool can = true;
			int c = B, i = 0;
			while(i < N){
				c -= ceil((double)nums[i]/(double)mid);
				//cout << c << '(' << ceil((double)nums[i]/(double)mid) << ')' << '\t';
				if(c < 0){
					can = false;
					break;
				}
				i++;
			}
			if(can){
				//cout << "CAN\n";
				r = mid;
			}
			else{
				//cout << "CANT\n";
				l = mid+1;
			}
		}
		cout << l << '\n';
	}
	
	return 0;
}