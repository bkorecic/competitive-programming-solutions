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

ll gcd(ll a, ll b){
	return b == 0 ? a : gcd(b, a%b);
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	double n, m, k; cin >> n >> m >> k;
	if(2.0*n*m/k != (ll)(2*n*m/k)){
		cout << "NO\n";
		return 0;
	}
	ll n1 = 2*n, n2 = m, denom = k;
	if(denom%2==0){
		n1/=2;
		denom/=2;
	}
	ll g;
	g = gcd(n1,denom);
	n1/=g; denom/=g;
	g = gcd(n2,denom);
	n2/=g; denom/=g;
	if(n1>n){
		n1/=2;
		n2*=2;
	}
	cout << "YES\n0 0\n0 " << n2 << "\n" << n1 << " 0\n";
	return 0;
}
