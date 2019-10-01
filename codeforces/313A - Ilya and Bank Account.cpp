#include <bits/stdc++.h>
using namespace std;

int main(){
	string N; cin >> N;
	int len = N.length();
	if(N[0] != '-'){
		cout << N << '\n';
		return 0;
	}
	if((int)N[len-2] >= (int)N[len-1]){
		N[len-2] = '*';
	}
	else{
		N[len-1] = '*';
	}
	
	if(N=="-0*" || N=="-*0"){
		cout << "0\n";
		return 0;
	}
	
	for(int i=0; i<len; i++){
		if(N[i] != '*')cout << N[i];
	}
	cout << '\n';
	return 0;
}