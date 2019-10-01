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
	int n, s, t; cin >> n >> s >> t;
	vector <int> p(n);
	for(int i=0; i<n; i++)cin>>p[i];
	int sinicial = s;
	int ans = 0;
	if(s==t){
		cout << "0\n";
		return 0;
	}
	while(true){
		s = p[s-1];
		ans++;
		if(s == t){
			cout << ans << '\n';
			return 0;
		}
		if(s == sinicial){
			cout << "-1\n";
			return 0;
		}
		
	}
	return 0;
}
