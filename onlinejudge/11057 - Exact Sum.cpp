#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;

typedef pair<int, int> ii;

typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ii> vii;

#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define EPS 1-e6
#define INF 1e6
#define PI acos(-1.0)

#define mp make_pair
#define pb push_back
#define f first
#define s second

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int N;
	while(cin>>N){
		vector <int> rep(1000001,0);
		for(int i=0; i<N; i++){
			int aux; cin >> aux;
			rep[aux]++;
		}
		int M; cin >> M;
		for(int i=M/2; i>=0; i--){
			if((rep[i]>0 && rep[M-i]>0 && i!=M-i) || (rep[i]>1 && M-i==i)){
				cout << "Peter should buy books whose prices are " << i << " and " << M-i << ".\n";
				break;
			}
		}
		cout << '\n';
	}
	return 0;
}
