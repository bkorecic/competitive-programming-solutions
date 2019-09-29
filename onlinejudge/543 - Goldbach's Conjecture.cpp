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
	vector <bool> sieve(1e6, true);
	sieve[0] = false;
	sieve[1] = false;
	for(int i=2; i<=1e3; i++){
		if(sieve[i]==true){
			for(int j=i; j<1e6/i; j++){
				sieve[i*j] = false;
			}
		}
	}
	vector <int> p;
	for(int i=2; i<sieve.size(); i++){
		if(sieve[i]==true)p.pb(i);
	}
	int N;
	
	//for(int i=0; i<10; i++) cout << p[i] << " " << sieve[p[i]] << endl;
	
	while(cin >> N, N!=0){
		for(int i=0; i<p.size(); i++){
			if(sieve[p[i]] == true && sieve[N-p[i]] == true){
				cout << N << " = " << p[i] << " + " << N-p[i] << '\n';
				break;
			}
		}
	} 
	return 0;
}
