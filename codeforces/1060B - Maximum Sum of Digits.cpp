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

int cantDigitos(ll n){
	if(n==0) return 0;
	else return cantDigitos(n/10) + 1;
}

int sumaDigitos(ll n){
	if(n==0) return 0;
	else return sumaDigitos(n/10) + n%10;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	ll n; cin >> n;
	ll a = n - (n%ll(pow(10, cantDigitos(n)-1)) + 1);
	cout << sumaDigitos(a) + sumaDigitos(n-a) << '\n';
	return 0;
}
