#include <bits/stdc++.h>
using namespace std;
long long parear(long long x){
	return (x*(x-1))/2;
}
int main(){
	long long N, M; cin >> N >> M;
	long long c1 = N/M;
	long long resto = N%M;
	long long comb1 = parear(c1);
	long long comb2 = parear(c1+1);
	long long minimos = (M-resto)*comb1 + resto*comb2;
	long long maximos = parear(N-M+1);
	cout << minimos << " " << maximos << '\n';
	return 0;
}