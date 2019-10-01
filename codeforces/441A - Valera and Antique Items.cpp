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
	int N, v; cin >> N >> v;
	vector <int> ans;
	for(int i=0; i<N; i++){
		bool can = false;
		int aux;
		cin >> aux;
		for(int k=0; k<aux; k++){
			int aux2; cin >> aux2;
			if(v>aux2){
				can = true;
			}
		}
		if(can==true)ans.push_back(i+1);
	}
	int sz = ans.size();
	cout << sz << '\n';
	for(int i=0; i<sz; i++){
		cout << ans[i] << " ";
	}
	cout << '\n';
	return 0;
}
