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
	vi n(N);
	for(int i=0; i<N; i++)cin >> n[i];
	int c = 2*N;
	int i = 0;
	int count = 0;
	int ans = 0;
	while(c--){
		if(n[(i+1)%N] >= n[i])count++;
		else {
			count = 0;
			ans = i+1;
		}
		if(count == N-1){
			if(ans == 0) cout << 0 << '\n';
			else cout << N-ans << '\n';
			return 0;
		}
		i = (i+1)%N;
	}
	cout << "-1\n";
	return 0;
}
