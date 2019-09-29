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

struct Hash{
	ll B;
	ll MOD;
	vector <ll> H;
	vector <ll> pot;
	int n;
	Hash(string &s, ll b, ll mod){
		n = s.length();
		B = b; MOD = mod;
		H.resize(n+1);
		pot.resize(n+1);
		H[n] = 0;
		pot[0] = 1;
		for(int i=1; i<=n; i++){
			pot[i] = pot[i-1]*B%MOD;
		}
		for(int i=n-1; i>=0; i--){
			H[i] = (s[i] + H[i+1]*B)%MOD;
		}
	}
	
	ll q(int i, int j){
		return (H[i] - H[j+1]*pot[j+1-i]%MOD + MOD)%MOD;
	}
	
};

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	string s; cin >> s;
	int n = s.length();
	Hash s_hash(s, 127, 1e9+7);
	for(int i = n-1; i>=1; i--){
		//cout << "compare: " << s.substr(0, i) << " con " << s.substr(n-i, i) << '\n';
		if(s_hash.q(0, i-1) == s_hash.q(n-i, n-1)){
			string ans = s.substr(0, i);
			for(int j=1; j<n-1; j++){
				if(j + i - 1 < n-1 && s_hash.q(j, j+i-1) == s_hash.q(0, i-1)){
					cout << ans << '\n';
					return 0;
				}
			}
		}
	}
	cout << "Just a legend\n";
	return 0;
}