#include <bits/stdc++.h>
using namespace std;

int main(){
	int N; cin >> N;
	vector <int> num(N);
	vector <bool> nBool(N,false);
	nBool[0] = true;
	if(N>1){
		nBool[1] = true;
	}
	for(int i=0; i<N; i++){
		cin >> num[i];
	}
	int best = 0;
	
	if(N==1){
		cout << "1" << endl;
		return 0;
	}
	else if(N==2){
		cout << "2" << endl;
		return 0;
	}
	//xd
	int bestAux = 0;
	for(int i=2; i<N; i++){
		if(num[i] == num[i-1] + num[i-2]){
			bestAux++;
		}
		else{
			bestAux = 0;
		}
		if(bestAux>best)best=bestAux;
	}
	cout << best + 2<< endl;
	return 0;
}