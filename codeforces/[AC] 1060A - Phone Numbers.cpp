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
	int other = 0, ochos = 0;
	for(int i=0; i<n; i++){
		char aux; cin >> aux;
		if(aux == '8')ochos++;
		else other++;
	}
	int ans = 0;
	while(ochos - 1 >= 0 && other - 10 >= 0){
		ans++;
		ochos--;
		other-=10;
	}
	int tot = ochos + other;
	while(ochos>=1 && tot>=11){
		ans++;
		ochos--;
		tot-=11;
	}
	cout << ans <<'\n';
	return 0;
}
