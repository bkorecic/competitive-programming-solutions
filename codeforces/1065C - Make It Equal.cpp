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
	int n, k; cin >> n >> k;
	vector <int> h(n);
	int minimo = 1e6, maximo = -1;
	for(int i=0; i<n; i++){
		cin>>h[i];
		if(h[i]<minimo)minimo=h[i];
		if(h[i]>maximo)maximo=h[i];
	}
	vector <int> count(maximo+1, 0);
	for(int i=0; i<n; i++){
		count[h[i]]++;
	}
	vector <int> sumas_h(maximo+1, 0);
	int suma = 0;
	for(int i = maximo; i>=1; i--){
		suma+=count[i];
		sumas_h[i]=suma;
	}
	int ans = 0;
	suma = 0;
	if(maximo==minimo){
		cout << "0\n";
		return 0;
	}
	for(int i = maximo; i>=minimo; i--){
		//cout << "suma actual = " << suma << "\tsumas_h[i] = " << sumas_h[i] << '\n';
		if(suma+sumas_h[i]>k || i == minimo){
			suma = sumas_h[i];
			ans++;
			continue;
		}
		suma+=sumas_h[i];
	}
	cout << ans << '\n';
	return 0;
}
