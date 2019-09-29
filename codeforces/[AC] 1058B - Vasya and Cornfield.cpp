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
	int n, d, m; cin >> n >> d >> m;
	//rectas x+d y x-d
	//rectas -x+d y -x+2n-d
	for(int rep=0; rep<m; rep++){
		int x,y; cin >> x >> y;
		if(y<=x+d && y>=x-d && y>=-x+d && y<=-x+2*n-d){
			cout << "YES\n";
		}
		else cout << "NO\n";
	}
	return 0;
}
