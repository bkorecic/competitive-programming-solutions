#include <bits/stdc++.h>
using namespace std;

int dp_vector(vector <int> lol){
	int N = lol.size();
	vector <int> dp(N);
	dp[0] = lol[0];
	dp[1] = max(lol[0], lol[1]);
	for(int i=2; i<N; i++)dp[i] = max(dp[i-1], lol[i] + dp[i-2]);
	return dp[N-1];
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int N, M;
	while(cin >> N >> M, N!=0){
		vector <int> compressed(N);
		vector <int> aux(M);
		for(int i=0; i<N; i++){
			for(int j=0; j<M; j++)cin >> aux[j];
			compressed[i] = dp_vector(aux);
		}
		cout << dp_vector(compressed) << '\n';
	}
	return 0;
}