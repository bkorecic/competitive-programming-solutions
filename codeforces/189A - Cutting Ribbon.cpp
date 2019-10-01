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
	vi x(3);
	vi dp(4001, -1);
	int n;
	cin >> n >> x[0] >> x[1] >> x[2];
	sort(x.begin(),x.end());
	
	dp[0] = 0;
	for(int i=1; i<=n; i++){
		int a,b,c;
		if(i-x[0]>=0){
			a = 1 + dp[i-x[0]];
		}
		else{
			a = -100000;
		}
		
		if(i-x[1]>=0){
			b = 1 + dp[i-x[1]];
		}
		else{
			b = -100000;
		}
		
		if(i-x[2]>=0){
			c = 1 + dp[i-x[2]];
		}
		else{
			c = -100000;
		}
		
		dp[i] = max(max(a,b), c);
	}
	cout << dp[n];
	return 0;
}
