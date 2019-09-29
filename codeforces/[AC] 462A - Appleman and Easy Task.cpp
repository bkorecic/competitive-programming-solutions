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
	char g[N][N];
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			cin >> g[i][j];
		}
	}
	for(int i=0; i<N; i++){
		// (1 0) (-1 0) (0 1) (0 -1)
		for(int j=0; j<N; j++){
			int count = 0;
			if(i+1<N){
				if(g[i+1][j] == 'o')count++;
			}
			if(i-1>=0){
				if(g[i-1][j] == 'o')count++;
			}
			if(j+1<N){
				if(g[i][j+1] == 'o')count++;
			}
			if(j-1>=0){
				if(g[i][j-1] == 'o')count++;
			}
			if(count%2 != 0){
				cout << "NO\n";
				return 0;
			}
		}
	}
	cout << "YES\n";
	return 0;
}
