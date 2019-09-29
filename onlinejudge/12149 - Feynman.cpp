#include <iostream>
#include <string>
#include <cmath>
using namespace std;


int main(){
	int N;
	cin >> N;
	while(N != 0){
		int suma = 0;
		for(int i=1; i<=N; i++){
			suma = suma + (i*i);
		}
		cout << suma << endl;
		cin >> N;
	}
return 0;
}

