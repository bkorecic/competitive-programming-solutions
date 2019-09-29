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
	int N; cin >> N;
	for(int rep = 0; rep<N; rep++){
		int K; cin >> K;
		map <char,ll> ch;
		for(int i=0;i<K; i++){
			char aux1; int aux2; 
			cin >> aux1 >> aux2;
			ch[aux1] = aux2;
		}
		int M; cin >> M;
		ll cost = 0;
		getchar();
		for(int i=0; i<M; i++){
			//ll debugCost = 0;
			string line;
			getline(cin,line);
			for(int k=0; k<line.length(); k++){
				cost += ch[line[k]];
				//debugCost += ch[line[k]];
			}
			//cout << "LINE: " << line << "\n" << "COST = " << debugCost << "\n";
		}
		ll dollars = cost/100;
		ll cents = cost%100;
		if(cents<=9){
			cout << dollars << ".0" << cents << "$\n";
		}
		else{
			cout << dollars << "." << cents << "$\n";
		}
	}
	return 0;
}
