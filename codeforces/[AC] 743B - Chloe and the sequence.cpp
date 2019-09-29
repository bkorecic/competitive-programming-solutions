#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int solve(int n, ll k){
	ll mid = pow(2, n-1);
	if(k < mid){
		return solve(n-1, k);
	}
	else if(k > mid){
		return solve(n-1, k - mid);
	}
	else{
		return n;
	}
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; ll k; cin >> n >> k;
	cout << solve(n, k) << '\n';
	return 0;
}