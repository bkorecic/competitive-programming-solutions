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
	int t; cin >> t;
	for(int i=0; i<t; i++){
		ll s, a, b, c;
		cin >> s >> a >> b >> c;
		ll canbuy = s/c;
		ll groups = canbuy/a;
		cout << canbuy + groups*b << '\n';
	}
	return 0;
}
