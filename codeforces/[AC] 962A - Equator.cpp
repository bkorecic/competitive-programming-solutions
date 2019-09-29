#include <bits/stdc++.h>
using namespace std;

int main(){
	//Optimizado con búsqueda binaria
	int N; cin >> N;
	int suma = 0;
	vector <int> sumas(N);
	for (int i=0; i<N; i++){
		int aux;
		cin >> aux;
		suma+=aux;
		sumas[i] = suma;
	}
	int half;
	if(sumas[N-1]%2==0){
		half = sumas[N-1]/2;
	}
	else{
		half = (sumas[N-1]/2) + 1;
	}
	//Binary Search
	int left = 0, right = N-1;
	int mid = (left+right)/2;
	while(left<right){
		if(sumas[mid] >= half){
			right = mid;
		}
		else{
			left = mid+1;
		}
		mid = (left+right)/2;
	}
	cout << mid+1 << '\n';
	
	return 0;
}