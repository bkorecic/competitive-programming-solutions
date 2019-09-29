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
	int n; cin >> n;
	vector <int> people(n+1, 0);
	for(int i=1; i<=n; i++) cin >> people[i];
	int ans = 1e8;
	for(int x=1; x<=n; x++){
		int contar = 0;
		for(int i=1; i<=n; i++){
			contar += people[i]*(abs(x-i)+abs(1-i)+abs(x-1));
		}
		if(contar < ans) ans = contar;
	}
	cout << 2*ans << '\n';
	return 0;
}