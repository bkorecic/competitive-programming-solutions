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
	ll n, m; cin >> n >> m;
	ll maximo = 0;
	ll minimo = max(0LL,n-2*m);
	for(ll i = 0; i<n; i++){
		if(((i*(i-1))/2)>=m){
			maximo = n-i;
			break;
		}
	}
	cout << minimo << ' ' << maximo << '\n';
	return 0;
}
