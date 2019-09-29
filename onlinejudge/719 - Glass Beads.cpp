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
	string s;
	int n;
	Hash(string &S, ll b, ll mod){
		s = S;
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
	
	bool lexCompare(int a, int b, int c, int d){
		int l = 0;
		int r = min(b-a+1, d-c+1);
		int mid;
		while(l < r){
			mid = (l+r)/2;
			if(q(a, a+mid-1) != q(c, c+mid-1)) r = mid;
			else l = mid+1;
		}
		if(s[a+l-1] < s[c+l-1]) return true;
		else return false;
	}
	
};

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int N; cin >> N;
	for(int caso = 1; caso<=N; caso++){
		string s; cin >> s;
		string search = s + s;
		int n = s.length();
		pair <int,int> ans = {0, n-1};
		Hash s_hash(search, 127, 1e9+7);
		for(int i=1; i<n; i++){
			if(s_hash.lexCompare(i, i+n-1, ans.f, ans.s)){
				ans = {i, i+n-1};
			}
		}
		cout << ans.f+1 << '\n';
	}
	return 0;
}