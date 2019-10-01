#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second
#define mp make_pair
#define pb push_back

typedef long long ll;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, k; cin >> n >> k;
	int ans = 0;
	for(int i=0; i<n; i++){
		int num; cin >> num;
		int len = log10(num) + 1;
		int lucky = 0;
		for(int j=0; j<len; j++){
			int digit = num%10;
			if(digit==4 or digit==7)lucky++;
			num/=10;
		}
		if(lucky <= k) ans++;
		
	}
	cout << ans << '\n';
	return 0;
}
