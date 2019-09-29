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
	string S; cin >> S;
	int count = 0;
	for(int i=0; i<S.length(); i++) if(S[i]=='1') count++;
	if(count%2==0) cout << S << "0\n";
	else cout << S << "1\n";
	return 0;
}
