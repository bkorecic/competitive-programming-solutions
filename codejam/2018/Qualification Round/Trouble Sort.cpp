#include <bits/stdc++.h>
using namespace std;

int main(){
	int T; cin >> T;
	for(int rep=0; rep<T; rep++){
		int N; cin >> N;
		vector <int> pares;
		vector <int> impares;
		for(int i=0;i<N;i++){
			int aux;
			cin >> aux;
			if(i%2==0){
				pares.push_back(aux);
			}
			else{
				impares.push_back(aux);
			}
		}
		sort(pares.begin(),pares.end());
		sort(impares.begin(),impares.end());
		vector <int> final(N);
		int k = 0;
		for(int i=0; k<N; i++){
			final[k] = pares[i];
			k+=2;
		}
		k = 1;
		for(int i=0; k<N; i++){
			final[k] = impares[i];
			k+=2;
		}
		
		
		cout << "Pares: ";
		for(int i=0; i<pares.size(); i++){
			cout << pares[i] << " ";
		}
		cout << '\n';
		cout << "Impares: ";
		for(int i=0; i<impares.size(); i++){
			cout << impares[i] << " ";
		}
		cout << '\n';
		cout << "Final: ";
		for(int i=0; i<N; i++){
			cout << final[i] << " ";
		}
		cout << '\n';
		
		
		for(int i=0; i<N-1; i++){
			if(final[i]>final[i+1]){
				cout << "Case #" << rep+1 << ": " << i << '\n';
				break;
			}
			if(i==N-2){
				cout << "Case #" << rep+1 << ": OK\n";
			}
		}
	}
	return 0;
}