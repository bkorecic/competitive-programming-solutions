#include <bits/stdc++.h>
using namespace std;

int main() {
	int N, M, K; cin >> N >> M >> K;
	vector <string> bits(M);
	string fedor;
	for(int i=0; i<M; i++){
		int aux; cin >> aux;
		bits[i] = bitset<20>(aux).to_string();
	}
	int aux2; cin >> aux2;
	fedor = bitset<20>(aux2).to_string();
	int count = 0;
	for(int i=0; i<M; i++){
		int differ = 0;
		for(int k=0; k<20; k++){
			if(bits[i][k] != fedor[k])differ++;
		}
		if(differ<=K)count++;
	}
	cout << count << '\n';
	return 0;
}