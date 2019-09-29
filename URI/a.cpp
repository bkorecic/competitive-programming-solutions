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
	double aux; cin >> aux;
	aux*=100;
	int N = aux;
	vii Monedas(12,{0,0});
	
	Monedas[0].f = 10000;		Monedas[1].f = 5000;
	Monedas[2].f = 2000;		Monedas[3].f = 1000;
	Monedas[4].f = 500;			Monedas[5].f = 200;
	Monedas[6].f = 100;			Monedas[7].f = 50;
	Monedas[8].f = 25;			Monedas[9].f = 10;
	Monedas[10].f = 5;			Monedas[11].f = 1;
	
	while(aux!=0){
		for(int i=0; i<12; i++){
			if(Monedas[i].f <= aux){
				aux-=Monedas[i].f;
				Monedas[i].s++;
				break;
			}
		}
	}
	
	cout << "NOTAS:\n";
	for(int i=0; i<6; i++){
		cout << Monedas[i].s << " nota(s) de R$ " << setprecision(2) << fixed << (double)Monedas[i].f/100 << '\n';
	}
	cout << "MOEDAS:\n";
	for(int i=6; i<12; i++){
		cout << Monedas[i].s << " moeda(s) de R$ " << setprecision(2) << fixed << (double)Monedas[i].f/100 << '\n';
	}
	
	return 0;
}