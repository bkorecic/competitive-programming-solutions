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
	vi ticket;
	for(int i=0;i<N;i++){
		char aux; cin >> aux;
		if(aux!='0'){
			ticket.pb((int)aux - (int)'0');
		}
	}
	int suma1 = 0;
	N=ticket.size();
	if(N==0){
		cout << "YES\n";
		return 0;
	}
	for(int i=0; i<N; i++){
		suma1+=ticket[i];
		int j = i+1;
		while(j<N){
			int suma2=0;
			while(j<N){
				suma2+=ticket[j];
				j++;
				if(suma2>=suma1)break;
			}
			if(suma2!=suma1)break;
			if(j==N){
				cout << "YES\n";
				return 0;
			}
		}
	}
	cout << "NO\n";
	return 0;
}
