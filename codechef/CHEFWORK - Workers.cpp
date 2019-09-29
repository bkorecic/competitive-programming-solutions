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
	int N, c; cin >> N;
	vi Ci(N);
	F0R(i, N)cin>>Ci[i];
	int minA = 1e6, minB = 1e6, minC = 1e6;
	F0R(i, N){
		cin >> c;
		if(c==1){
			if(Ci[i] < minA)minA=Ci[i];
		}
		else if(c==2){
			if(Ci[i] < minB)minB=Ci[i];
		}
		else{
			if(Ci[i] < minC)minC=Ci[i];
		}
	}
	cout << min((minA+minB),minC);
	return 0;
}
