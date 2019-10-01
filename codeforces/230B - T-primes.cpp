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
	int N; cin >> N;
	//Criba hasta 1e6
	vector <bool> isPrime(1e6+1, true);
	isPrime[1] = false;
	for(int i=2; i<=1e3+1; i++){
		if(isPrime[i] == true) {
			int a = 2;
			while(i*a <= 1e6+1){
				isPrime[i*a] = false;
				a++;
			}
		}
	}
	for(int i=0; i<N; i++){
		ll aux; cin >> aux;
		bool sqInteger = false;
		double sqD = sqrt(aux);
		int sqI = sqrt(aux);
		if(sqD - sqI == 0) sqInteger = true;
		if(sqInteger == true && isPrime[sqrt(aux)]) cout << "YES\n";
		else cout << "NO\n";
	}
	
	
	return 0;
}
