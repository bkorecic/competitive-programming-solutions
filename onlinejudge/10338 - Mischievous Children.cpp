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

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int N; cin >> N;
	vector <unsigned long long int> fact(21);
	fact[0] = 1;
	for(int i=1; i<=20; i++){
		fact[i] = fact[i-1]*i;
	}
	for(int rep = 1; rep<=N; rep++){
		vector <int> count(27,0);
		string s; cin >> s;
		for(int i=0; i<s.length(); i++){
			count[s[i]-'A']++;
		}
		unsigned long long int nomin = fact[s.length()];
		unsigned long long int denom = 1;
		for(int i=0; i<27; i++){
			denom *= fact[count[i]];
		}
		cout << "Data set " << rep << ": " << nomin/denom << '\n';
	}
	return 0;
}
