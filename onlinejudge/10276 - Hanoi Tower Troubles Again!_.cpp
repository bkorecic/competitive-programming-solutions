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
int N, ans;
vector <int> last;
bool done;
void backtrack(int actual = 1){
	if(done)return;
	if(actual > ans) ans = actual;
	for(int i=0; i<N; i++){
		int ult = last[i];
		if(ult == -1 || sqrt(actual+ult) == int(sqrt(actual+ult))){
			last[i] = actual;
			backtrack(actual+1);
			last[i] = ult;
		}
	}
	done = true; //greedy
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int T; cin >> T;
	for(int rep = 0; rep < T; rep ++){
		done = false;
		ans = 0;
		cin >> N;
		last.assign(N, -1);
		backtrack();
		cout << ans-1 << '\n';
	}
	return 0;
}
