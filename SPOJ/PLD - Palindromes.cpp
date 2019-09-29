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
	ll B, MOD;
	vector <ll> H;
	vector <ll> pot;
	int n;
	Hash(string s, ll b, ll mod){
		MOD = mod;
		B = b;
		n = s.length();
		H.resize(n+1);
		pot.resize(n+1);
		pot[0] = 1;
		H[n] = 0;
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
	int k, n; string s;
	cin >> k >> s;
	n = s.length();
	string rs = s;
	for(int i=0; i<n; i++) rs[i] = s[n-1-i];
	Hash s_hash(s, 127, 1e9+7);
	Hash rs_hash(rs, 127, 1e9+7);
	int ans = 0;
	int i = 0;
	while(i+k-1 < n){
		int j = i+k-1;
		if(s_hash.q(i, j) == rs_hash.q(n-j-1, n-i-1))ans++;
		i++;
	}
	cout << ans << '\n';
	return 0;
}
