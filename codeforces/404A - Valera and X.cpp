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
	char m[n][n];
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cin >> m[i][j];
		}
	}
	char diag = m[0][0], other = m[0][1];
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(i==j || i+j == n-1){
				if(m[i][j] != diag){
					cout << "NO\n";
					return 0;
				}
			}
			else{
				if(m[i][j] != other || m[i][j] == diag){
					cout << "NO\n";
					return 0;
				}
			}
		}
	}
	cout << "YES\n";
	return 0;
}
