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
	int n; cin >> n;
	if(n%2==0){
		for(int i=1; i<=n; i++){
			if(i!=1)cout << ' ';
			if(i%2!=0)cout << i+1;
			else cout << i-1;
			
		}
	}
	else cout << "-1\n";
	
	return 0;
}
