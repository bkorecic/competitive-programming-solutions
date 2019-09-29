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

bool isPrime(ll x){
	for(ll i=2; i<=sqrt(x); i++){
		if(x%i==0)return false;
	}
	return true;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t; cin >> t;
	for(int i=0; i<t; i++){
		ll a, b;
		cin >> a >> b;
		if(a-b==1 && isPrime(a+b))cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}
