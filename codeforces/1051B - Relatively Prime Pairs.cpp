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
	cout << "YES\n";
	ll L,R; cin >> L >> R;
	for(ll i=L; i<=R; i++){
		cout << i << ' ' << i+1 << '\n';
		i++;
	}
	
	
	
	
	return 0;
}
