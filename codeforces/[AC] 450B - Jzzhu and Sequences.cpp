#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;

typedef pair<int, int> ii;

typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ii> vii;

#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define MOD 1000000007
#define mp make_pair
#define pb push_back
#define f first
#define s second

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	ll x, y, n; cin >> x >> y >> n;
	vector <ll> ans(12);
	ans[0] = x;
	ans[1] = y;
	for(int i=2; i<=11; i++){
		ans[i] = ans[i-1] - ans[i-2];
	}
	cout << (ans[(n-1)%12]%MOD + MOD)%MOD << '\n';

	return 0;
}
