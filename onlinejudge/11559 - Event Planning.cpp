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
	int N, B, H, W;
	while(cin >> N){
		cin >> B >> H >> W;
		int ans = 1e9;
		for(int i=0; i<H; i++){
			int p; cin >> p;
			bool elegible = false;
			for(int j=0; j<W; j++){
				int aux; cin >> aux;
				if(aux>=N){
					elegible = true;
				}
			}
			if(elegible==true && p*N <= B && p*N <= ans){
				ans = p*N;
			}
		}
		if(ans==1e9) cout << "stay home\n";
		else cout << ans << '\n';
	}
	
	
	
	
	return 0;
}
