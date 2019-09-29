#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,m,a,b; cin >> n >> m >> a >> b;
	if(b <= a*m){
	cout << min(b*(n/m) + a*(n%m),b*((n/m) + 1)) << '\n';
	return 0;
	}
	else{
	cout << a*n << '\n';
	}
	return 0;
}