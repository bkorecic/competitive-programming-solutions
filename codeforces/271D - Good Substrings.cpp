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
	string s; cin >> s;
	int n = s.length();
	map <char, int> dict;
	string aux; cin >> aux;
	int k; cin >> k;
	for(int i=0; i<aux.size(); i++){
		dict['a' + i] = 1-(aux[i] - '0');
	}
	vector <int> nums(n);
	for(int i=0; i<n; i++){
		nums[i] = dict[s[i]];
	}
	vector <int> sumas(n);
	int sum = 0;
	for(int i=0; i<n; i++){
		sum += nums[i];
		sumas[i] = sum;
	}
	vector <ll> H(n+1);
	vector <ll> H2(n+1);
	H[n] = 0;
	H2[n] = 0;
	vector <ll> pot(n+1);
	vector <ll> pot2(n+1);
	pot[0] = 1;
	pot2[0] = 1;
	int B = 193;
	int B2 = 127;
	ll MOD = 1e9 + 7;
	ll MOD2 = 1e9 + 9;
	for(int i=1; i<=n; i++){
		pot[i] = pot[i-1]*B%MOD;
		pot2[i] = pot2[i-1]*B2%MOD2;
	}
	for(int i = n-1; i>=0; i--){
		H[i] = (s[i] + H[i+1]*B)%MOD;
		H2[i] = (s[i] + H2[i+1]*B2)%MOD2;
	}
	auto hash = [&](int i, int j) { return (H[i] - H[j+1]*pot[j-i+1]%MOD + MOD)%MOD;};
	auto hash2 = [&](int i, int j) { return (H2[i] - H2[j+1]*pot2[j-i+1]%MOD2 + MOD2)%MOD2;};
	set <pair<ll,ll>> ans;
	for(int i=0; i<n; i++){
		for(int j=i; j<n; j++){
			int restar;
			if(i == 0) restar = 0;
			else restar = sumas[i-1];
			if(sumas[j] - restar <= k){
				ans.insert({hash(i,j), hash2(i,j)});
			}
			else break;
		}
	}
	//for(auto v : ans) cout << v.f << ' ' << v.s << endl;
	//cout << endl;
	cout << ans.size() << '\n';
	return 0;
}
