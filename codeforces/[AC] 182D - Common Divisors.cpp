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
	vector <ll> H;
	vector <ll> pot;
	int n;
	ll B, MOD;
	Hash(string s, ll b, ll mod){
		n = s.length();
		B = b; MOD = mod;
		H.resize(n+1);
		pot.resize(n+1);
		pot[0] = 1;
		for(int i=1; i<=n; i++){
			pot[i] = (pot[i-1]*B)%MOD;
		}
		H[n] = 0;
		for(int i = n-1; i>=0; i--){
			H[i] = (s[i] + H[i+1]*B)%MOD;
		}
	}
	ll q(int i, int j){
		return (H[i] - H[j+1]*pot[j-i+1]%MOD + MOD)%MOD;
	}	
};

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	string s1, s2; cin >> s1 >> s2;
	int len1 = s1.length(), len2 = s2.length();
	int gcd = __gcd(len1, len2);
	int ans = 0;
	Hash s1_h(s1, 127, 1e9+7);
	Hash s2_h(s2, 127, 1e9+7);
	for(int d=1; d<=gcd; d++){
		if(gcd%d == 0){
			ll hash_obj = s1_h.q(0,d-1);
			int i = 0, j = 0;
			bool possible = true;
			while(i < len1 or j < len2){
				if(i < len1 && s1_h.q(i, i+d-1) != hash_obj){
					possible = false;
					break;
				}
				if(j < len2 && s2_h.q(j, j+d-1) != hash_obj){
					possible = false;
					break;
				}
				i+=d, j+=d;
			}
			if(possible){
				ans++;
			}
		}
	}
	cout << ans << '\n';
	return 0;
}
