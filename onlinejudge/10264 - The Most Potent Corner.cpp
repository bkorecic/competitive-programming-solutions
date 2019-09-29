#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;

typedef pair<int, int> ii;

typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ii> vii;

#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)

#define mp make_pair
#define pb push_back
#define f first
#define s second

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int N;
	while(cin>>N){
		vector <int> b(pow(2,N)); // input
		vector <int> w(pow(2,N)); // weight neighbors sum
		//cin
		for(int i=0; i<pow(2,N); i++){
			cin >> b[i];
		}
		//calculate weights
		for(int i=0; i<pow(2,N); i++){
			int weight = 0;
			for(int j=0; j<N; j++){
				int pot = pow(2,j);
				weight += b[i^pot];
			}
			w[i] = weight;
		}
		//max sum, brute force
		int ans = 0;
		for(int i=0; i<pow(2,N); i++){
			for(int j=0; j<N; j++){
				int pot = pow(2,j);
				if(w[i] + w[i^pot] > ans) {
					ans =  w[i] + w[i^pot];
				}
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
