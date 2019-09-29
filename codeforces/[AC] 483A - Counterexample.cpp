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
	ll l, r; cin >> l >> r;
	if(r-l+1 < 3){
		cout << "-1\n";
	}
	else if(l%2==0){
		cout << l << ' ' << l+1 << ' ' << l+2 << '\n';
	}
	else if(r-l+1>3){
		cout << l+1 << ' ' << l+2 << ' ' << l+3 << '\n';
	}
	else cout << "-1\n";
	
	return 0;
}
