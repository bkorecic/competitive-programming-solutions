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
	int N,K;
	while(cin>>N>>K, N!=0){
		vector <int> numb(101,0);
		int count = 0;
		for(int i=0; i<N; i++){
			int aux; cin >> aux;
			if(numb[aux] != -1) numb[aux]++;
			if(numb[aux]>=K){
				count++;
				numb[aux] = -1;
			}
		}
		cout << count << '\n';
	}
	return 0;
}
