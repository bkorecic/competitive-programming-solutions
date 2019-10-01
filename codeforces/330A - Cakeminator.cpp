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
	int R, C, eaten; cin >> R >> C;
	char g[R][C];
	for(int i=0; i<R; i++){
		for(int j=0; j<C; j++){
			cin >> g[i][j];
		}
	}
	int ans = 0;
	//Recorrer horizontal
	for(int i=0; i<R; i++){
		bool evil = false;
		eaten = 0;
		for(int j=0; j<C; j++){
			if(g[i][j] == 'S'){
				evil = true;
				break;
			}
		}
		if(evil == false){
			for(int j=0; j<C; j++){
				if(g[i][j] == '.'){
					eaten++;
					g[i][j] = '*';
				}
			}
		}
		ans+=eaten;
	}
	//Rec vertical
	for(int j=0; j<C; j++){
		bool evil = false;
		eaten = 0;
		for(int i=0; i<R; i++){
			if(g[i][j] == 'S'){
				evil = true;
				break;
			}
		}
		if(evil == false){
			for(int i=0; i<R; i++){
				if(g[i][j] == '.'){
					eaten++;
					g[i][j] = '*';
				}
			}
		}
		ans+=eaten;
	}
	cout << ans << '\n';
	return 0;
}
