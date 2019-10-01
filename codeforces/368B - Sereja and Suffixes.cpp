#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;

typedef pair<int, int> ii;

typedef vector<int> vi;
typedef vector<ii> vii;

#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)

#define mp make_pair
#define pb push_back
#define f first
#define s second

int main(){
	int n, m, c; cin >> n >> m;
	vi sq(n+1);
	sq[0] = -1; //1-indexing
	vector <bool> fq(1e5+10,0);
	vi dp(1e5+10,0);
	for(int i=1; i<=n; i++)cin>>sq[i];
	
	dp[n] = 1;
	fq[sq[n]] = true;
	
	for(int i=n-1; i>0; i--){
		dp[i] = dp[i+1] + !fq[sq[i]];
		fq[sq[i]] = true;
	}
	F0R(i, m){
		cin >> c;
		cout << dp[c] << '\n';
	}
	
	return 0;
}
