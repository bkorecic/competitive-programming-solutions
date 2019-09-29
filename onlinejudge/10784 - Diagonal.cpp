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
	double K; 
	int caso = 1;
	while(cin >> K, K!=0){
		double x = (sqrt(9.0+8.0*K)+3.0)*0.5;
		//cout << "x= " <<x << endl;
		long long ans = x;
		if(x-ans > 1e-9){
			ans++;
		}
		cout << "Case " << caso << ": " << ans << '\n';
		caso++;
	}
	return 0;
}
