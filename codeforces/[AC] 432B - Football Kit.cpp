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
	int n; cin >> n;
	vector <pair<int,int>> kits(n);
	vector <int> countFirst(1e5+1,0);
	vector <int> countAway(1e5+1,0);
	for(int i=0; i<n; i++){
		cin >> kits[i].f >> kits[i].s;
		countFirst[kits[i].f]++;
		countAway[kits[i].s]++;
	}
	for(int i=0; i<n; i++){
		cout << countFirst[kits[i].s] + n-1 << ' ' << n-countFirst[kits[i].s]-1 << '\n';
	}
	return 0;
}
