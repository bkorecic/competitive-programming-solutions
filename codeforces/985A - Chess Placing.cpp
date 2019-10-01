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
	vi pos(N/2);
	F0R(i, N/2){
		int aux;
		cin >> aux;
		pos[i] = aux;
	}
	sort(pos.begin(),pos.end());
	int count1 = 0, count2 = 0;
	for(int i = 1; i<=N/2; i++){
		count1 += abs(pos[i-1] - 2*i);
		count2 += abs(pos[i-1] - (2*i-1));
	}
	cout << min(count1,count2) << '\n';
	return 0;
}
