#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, d; cin >> n >> d;
	int suma = 0;
	for(int i=0; i<n; i++){
		int aux; cin >> aux;
		suma+=aux;
	}
	int total = suma + 10*(n-1);
	if(total>d){
		cout << -1 << '\n';
		return 0;
	}
	int ch = 2*(n-1) + (d-total)/5;
	cout << ch << '\n';
	return 0;
}