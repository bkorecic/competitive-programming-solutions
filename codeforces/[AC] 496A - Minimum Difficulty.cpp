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
	int n; cin >> n;
	vector <int> a(n);
	for(int i=0; i<n; i++)cin>>a[i];
	int ans = 1e9;
	for(int i=1; i<=n-2; i++){
		int maxim = -1;
		for(int k=1; k<n; k++){
			int comp = a[k]-a[k-1];
			if(k==i)continue;
			if(k==i+1){
				comp = a[k]-a[k-2];
			}
			if(comp>maxim)maxim=comp;
		}
		if(maxim < ans)ans = maxim;
	}
	cout << ans << '\n';
	
	return 0;
}
