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
	int n, ax, ay, bx, by, cx, cy;
	cin >> n >> ax >> ay >> bx >> by >> cx >> cy;
	bool pos = true;
	int xdist = abs(bx-cx);
	int ydist = abs(by-cy);
	if(abs(ax-cx) <= xdist && abs(ax-bx) <= xdist)pos=false;
	if(abs(ay-cy) <= ydist && abs(ay-by) <= ydist)pos=false;
	if(pos)cout << "YES\n";
	else cout << "NO\n";
	return 0;
}
