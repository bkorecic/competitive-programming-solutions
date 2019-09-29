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
	Hash(string &s, ll b, ll mod){
		B = b;
		MOD = mod;
		n = s.length();
		H.resize(n+1);
		pot.resize(n+1);
		H[n] = 0;
		pot[0] = 1;
		for(int i=1; i<n+1; i++){
			pot[i] = pot[i-1]*B%MOD;
		}
		for(int i=n-1; i>=0; i--){
			H[i] = s[i]-'A'+1 + H[i+1]*B%MOD;
		}
	}
	
	ll q(int i, int j){
		return (H[i] - H[j+1]*pot[j+1-i]%MOD + MOD)%MOD;
	}
};

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	string s;
	ll MOD = 1e9+7;
	while(cin >> s){
		int n = s.length();
		string rs = s;
		reverse(rs.begin(), rs.end());
		Hash s_h(s, 127, MOD);
		Hash rs_h(rs, 127, MOD);
		if(s_h.q(0,n-1) == rs_h.q(0,n-1)){
			cout << s << '\n';
		}
		else{
			for(int i=0; i<n; i++){
				if((s_h.q(0,n-1) + rs_h.q(n-1-i, n-1)*s_h.pot[n]%MOD)%MOD == (s_h.q(0, i) + rs_h.q(0, n-1)*s_h.pot[i+1]%MOD)%MOD){
					cout << s + rs.substr(n-1-i, i+1) << '\n';
					break;
				}
			}
		}
	}
	return 0;
}
