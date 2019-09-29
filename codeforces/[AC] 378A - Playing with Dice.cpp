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
	int a,b; cin >> a >> b;
	int wa = 0, draw = 0, wb = 0;
	for(int i=1; i<=6; i++){
		if(abs(i-a)<abs(i-b))wa++;
		else if(abs(i-a)>abs(i-b))wb++;
		else draw++;
	}
	cout << wa << " " << draw << " " << wb << '\n';
	
	return 0;
}
