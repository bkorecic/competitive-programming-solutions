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
	int n; cin >> n;
	vector <int> contar(101, 0);
	for(int i=0; i<n; i++){
		int r; cin >> r;
		for(int j=0; j<r; j++){
			int aux; cin >> aux;
			contar[aux]++;
		}
	}
	for(int i=1; i<101; i++){
		if(contar[i] == n){
			if(i!=1) cout << ' ' << i;
			else cout << i;
		}
	}
	cout << '\n';
	return 0;
}