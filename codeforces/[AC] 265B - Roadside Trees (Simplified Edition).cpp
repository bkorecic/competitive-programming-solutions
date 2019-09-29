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
	int N; cin >> N;
	int h, hlast, ans = 0;
	cin >> h;
	ans+=h+1;
	hlast = h;
	for(int i=0; i<N-1; i++){
		cin >> h;
		ans+=abs(h-hlast)+2;
		hlast = h;
	}
	cout << ans << '\n';
	return 0;
}
