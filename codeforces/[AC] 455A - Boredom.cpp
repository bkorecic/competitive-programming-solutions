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
	vector <ll> fq(1e5+7,0);
	vector <ll> dp(1e5+7,0);
	ll n, c; cin >> n;
	ll mayor = 1;
	for(ll i=0; i<n; i++){
		cin >> c;
		fq[c]++;
		if(c>mayor)mayor=c;
	}
	dp[0] = 0;
	dp[1] = fq[1];
	for(ll i=2; i<=1e5; i++){
		dp[i] = max(dp[i-1], dp[i-2] + i*fq[i]);
	}
	cout << dp[1e5] << '\n';
	return 0;
}