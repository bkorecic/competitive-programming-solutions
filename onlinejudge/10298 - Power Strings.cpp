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
	int B = 127;
	ll mod = 1e9 + 7;
	vector <ll> pot(1e6+1);
	pot[0] = 1;
	for(int i=1; i<1e6+1; i++){
		pot[i] = pot[i-1] * B;
	}
	string s;
	while(cin >> s, s != "."){
		int n = s.length();
		vector <int> divisores;
		
		for(int i=1; i<=n; i++){
			if(n%i == 0) divisores.pb(i);
		}
		vector<ll> Hash(n);
		Hash[n-1]=s[n-1];
		for(int i=n-2;i>=0;i--){
			Hash[i]=(int)s[i] + Hash[i+1]*B;
		}
		for(int d : divisores){
			bool done = false;
			int i = 0;
			ll hash_div = Hash[0] - Hash[d]*pot[d];
			while(i < n){
				i+=d;
				if(i >= n){
					cout << n/d << '\n';
					done = true;
					break;
				}
				ll hash_actual = Hash[i] - Hash[i+d]*pot[d];
				if(hash_actual != hash_div){
					break;
				}
			}
			if(done) break;
		}
	}
	
	
	return 0;
}
