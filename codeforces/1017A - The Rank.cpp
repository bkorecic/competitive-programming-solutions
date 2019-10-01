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

bool rankSort (ii p1, ii p2){
	if(p1.f>p2.f || (p1.f==p2.f && p1.s <= p2.s)) return true;
	return false;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int N; cin >> N;
	vii pp(N);
	for(int i=0; i<N; i++){
		int a,b,c,d; cin >> a >> b >> c >> d;
		pp[i] = mp(a+b+c+d, i+1);
	}
	sort(pp.begin(),pp.end(),rankSort);
	for(int i=0; i<N; i++){
		if(pp[i].s == 1){
			cout << i+1 << '\n';
			break;
		}
	}
	
	return 0;
}
