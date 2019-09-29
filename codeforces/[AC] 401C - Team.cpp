#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, m; cin >> n >> m;
	if(m > 2*n + 2 || n > m+1){
		cout << -1 << '\n';
		return 0;
	}
	if(n == m+1){
		cout << 0;
		n--;
	}
	while(n>0 && m>0){
		if(n == m){
			cout << 10;
			n--; m--;
		}
		else{
			cout << 110;
			n--; m-=2;
		}
	}
	while(m>0){
		cout << 1; m--;
	}cout << '\n';
	return 0;
}
