#include <bits/stdc++.h>
using namespace std;

int main(){
	long long N, K; cin >> N >> K;
	if(N==1){
		cout << "1\n";
		return 0;
	}
	long long mitad = N/2;
	if(N%2 != 0)mitad = (N+1)/2;
	if(K <= mitad){
	cout << (2*K)-1 << '\n';
	}
	else{
		K -= mitad;
		cout << 2*K << '\n';
	}
	return 0;
}