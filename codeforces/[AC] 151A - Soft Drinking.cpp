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
	int n, k, l, c, d, salt, nl, np;
	cin >> n >> k >> l >> c >> d >> salt >> nl >> np;
	int slices = c*d;
	int volume = k*l;
	
	int ans = 0;
	while(slices >= 0 && volume >= 0 && salt >= 0){
		ans++;
		slices-=n;
		volume-=n*nl;
		salt-=n*np;
		//cout << "Ans = " << ans << " |  Volume = " << volume << " | Salt = " << salt << endl;
	} 
	cout << ans-1 << '\n';
	return 0;
}
