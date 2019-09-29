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
int t, n;
vector <vector <int>> printear;
vector <int> numeros;
vector <bool> candidatos;

void backtrack(int suma = 0, int iactual = 0){
	if(suma>t){
		return;
	}
	if(suma==t){
		vector <int> ans;
		for(int i=0; i<n; i++){
			if(candidatos[i] == false){
				ans.push_back(numeros[i]);
			}
		}
		//sort(ans.begin(), ans.end(), greater <int>());
		printear.push_back(ans);
		return;
	}
	for(int i=iactual; i<n; i++){
		if(candidatos[i]){
			candidatos[i] = false;
			backtrack(suma+numeros[i], i+1);
			candidatos[i] = true;
		}
	}
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	while(cin >> t >> n, t!=0){
		printear.clear();
		numeros.assign(n,0);
		candidatos.assign(n,true);
		for(int i=0; i<n; i++)cin>>numeros[i];
		sort(numeros.begin(), numeros.end(), greater <int>());
		backtrack();
		
		sort(printear.rbegin(), printear.rend());
		cout << "Sums of " << t << ":\n";
		for(size_t i=0; i<printear.size(); i++){
			if(i!=printear.size()-1 && printear[i] == printear[i+1])continue;
			for(size_t j=0; j<printear[i].size(); j++){
				cout << printear[i][j];
				if(j != printear[i].size()-1)cout << '+';
			}
			cout << '\n';
		}
		if(printear.size() == 0){
			cout << "NONE\n";
		}
	}
	return 0;
}
