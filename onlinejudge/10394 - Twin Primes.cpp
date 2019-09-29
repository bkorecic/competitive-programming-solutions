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
	//sieve
	const int cribar = 2*1e7;
	vector <bool> sieve(cribar,true);
	sieve[0] = false; sieve[1] = false;
	for(int i=2; i<=sqrt(cribar); i++){
		if(sieve[i]==true){
			for(int j=i; j<cribar/i; j++){
				sieve[i*j] = false;
			}
		}
	}
	vector <int> twins;
	for(int i=2; i<=2*1e7; i++){
		if(sieve[i] && sieve[i+2])twins.pb(i);
	}
	int S;
	while(cin >> S){
		int ans = twins[S-1];
		cout << '(' << ans << ", " << ans+2 << ")\n";
	}
	return 0;
}
