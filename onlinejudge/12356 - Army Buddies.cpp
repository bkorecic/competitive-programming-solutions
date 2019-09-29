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
	int S, B;
	while(cin >> S >> B, S != 0){
	set <int> alive;
	for(int i=1; i<=S; i++)alive.insert(i);
	for(int i=0; i<B; i++){
		int L, R; cin >> L >> R;
		for(int j = L; j<=R; j++){
			alive.erase(j);
		}
		auto it = alive.lower_bound(L);
		if(it != alive.begin()){
			cout << *--it;
		}
		else {
			cout << '*';
		}
		it = alive.upper_bound(R);
		cout << ' ';
		if(it != alive.end()){
			cout << *it << '\n';
		}
		else{
			cout << '*' << '\n';
		}
	}
	cout << "-\n";
	}
	return 0;
}
