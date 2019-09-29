#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;

typedef pair<int, int> ii;

typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ii> vii;

#define mp make_pair
#define pb push_back
#define f first
#define s second

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n,h; cin >> n >> h;
	int ans = 0;
	for(int i=0; i<n; i++){
		int aux; cin >> aux;
		if(aux > h)ans+=2;
		else ans++;
	}
	cout << ans << '\n';
	return 0;
}