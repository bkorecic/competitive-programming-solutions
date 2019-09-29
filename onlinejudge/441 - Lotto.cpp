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

int k;
vector <int> S;
vector <bool> used;

void backtrack(int iactual = 0, int picked = 0, vector <int> ans = {}){
	if(picked==6){
		for(int i=0; i<6; i++){
			if(i!=0)cout << ' ';
			cout << ans[i];
		}
		cout << '\n';
		return;
	}
	for(int i=iactual; i<k; i++){
		if(used[i] == false){
			used[i] = true;
			vector <int> next = ans;
			next.push_back(S[i]);
			backtrack(i+1, picked+1, next);
			used[i] = false;
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	bool first = true;
	while(cin >> k, k!=0){
		if(!first)cout << '\n';
		S.assign(k,'0');
		used.assign(k, false);
		for(int i=0; i<k; i++) cin >> S[i];
		backtrack();
		first = false;
	}	
	return 0;
}
