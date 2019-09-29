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
	int L, C, R1, R2;
	while(cin >> L >> C >> R1>> R2, L != 0){
		bool can = false;
		int mini = min(L,C);
		int a = L-R1-R2;
		int b = C-R1-R2;
		if(2*R1 > mini || 2*R2 > mini){
			
		}
		else if(a*a + b*b >= (R1+R2)*(R1+R2)){
			can = true;
		}
		if(can) cout << "S\n";
		else cout << "N\n";
		
	}
	
	
	
	return 0;
}
