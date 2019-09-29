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

vector <string> rotate(vector<string> &a){
	int N = a.size();
	vector <string> ans = a;
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			ans[j][i] = a[N-1-i][j];
		}
	}
	return ans;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int N, n;
	vector <string> test = {"ABC","DEF","GHI"};
	
	while(cin >> N >> n, N!=0){
		vector <string> big, small;
		for(int i=0; i<N; i++){
			string aux; cin >> aux;
			big.pb(aux);
		}
		for(int i=0; i<n; i++){
			string aux; cin >> aux;
			small.pb(aux);
		}
		
		for(int rot=0; rot<4; rot++){
			int ans = 0;
			for(int i=0; i<N-n+1; i++){
				for(int j=0; j<N-n+1; j++){
					if(big[i][j] == small[0][0]){
						bool can = true;
						for(int p = 0; p<n; p++){
							for(int q = 0; q<n; q++){
								if(big[i+p][j+q] != small[p][q]){
									can=false;
									break;
								}
							}
							if(!can)break;
						}
						if(can){
							ans++;
						}
					}
				}
			}
			if(rot==0) cout << ans;
			else cout << ' ' << ans;
			small = rotate(small);
		}
		cout << '\n';
	}
	return 0;
}
