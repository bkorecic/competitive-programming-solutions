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

int gcd(int a,int b){
	while(a!=b){
		if(a>b){
			a = a-b;
		}
		else{
			b = b-a;
		}
	}
	return a;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int N; cin >> N;
	vi num(N);
	int original_gcd;
	for(int i=0; i<N; i++){
		cin >> num[i];
	}
	original_gcd = num[0];
	for(int i=1; i<N; i++)original_gcd = gcd(original_gcd, num[i]);
	
	
	
	return 0;
}
