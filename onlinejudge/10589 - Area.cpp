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
	double N, a;
	while(cin >> N >> a, N!=0){
		double M = 0;
		for(int i=0; i<N; i++){
			double x, y; cin >> x >> y;
			double d1 = sqrt(x*x + y*y);
			double d2 = sqrt((x-a)*(x-a) + y*y);
			double d3 = sqrt(x*x + (y-a)*(y-a));
			double d4 = sqrt((x-a)*(x-a) + (y-a)*(y-a));
			if(d1 <= a && d2 <= a && d3 <= a && d4 <= a) M++;
		}
		cout << fixed << setprecision(5) << M*a*a/N << '\n';
	}
	return 0;
}
