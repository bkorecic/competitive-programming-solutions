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
	int N;
	while(cin >> N, N!=0){
		int dir = 0;
		for(int i=0; i<N; i++){
			char aux; cin >> aux;
			if(aux=='D'){
				dir = (dir+1)%4;
			}
			else{
				dir = (dir+3)%4;
			}
		}
		if(dir==0) cout << "N\n";
		else if(dir==1) cout << "L\n";
		else if(dir==2) cout << "S\n";
		else if(dir==3) cout << "O\n";
	}
	return 0;
}
