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

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int N, M; cin >> N >> M;
	map <string, string> dict;
	for(int i=0; i<M; i++){
		string a, b; cin >> a >> b;
		int len1 = a.length(), len2 = b.length();
		if(len1>len2){
			dict[a] = b;
		}
		else {
			dict[a] = a;
		}
	}
	for(int i=0; i<N; i++){
		string aux; cin >> aux;
		cout << dict[aux] << " ";
	}
	cout << '\n';
	return 0;
}
