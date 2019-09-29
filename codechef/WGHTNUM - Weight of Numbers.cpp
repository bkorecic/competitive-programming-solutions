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
#define MOD 1000000007
int main(){
	vi formas(19);
	for(int i=0; i<10; i++){
		for(int k=0; k<10; k++){
			if(k!=0)formas[i-k+9]++;
		}
	}
	long long T, N, W;
	cin >> T;
	
	while(T--){
		cin >> N >> W;
		long long exp = N-2;
		long long ans = 1;
		int count = 0;
		for(long long i=0; i<N-2; i++){
			ans*=10;
			count++;
			if(count==8){
				ans = ans%(MOD);
				count=0;
			}
		}
		ans*= formas[W+9];
		ans = ans%(MOD);
		cout << ans << '\n';
	}
	
	
	
	return 0;
}
