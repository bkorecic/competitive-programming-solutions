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
	//messy code
	ll ts, tf, t, N; 
	cin >> ts >> tf >> t >> N;
	if(N==0){
		cout << ts << '\n';
		return 0;
	}
	vector <ll> P(N);
	for(int i=0; i<N; i++) cin >> P[i];
	ll dead_time;
	if(P[0] <= ts){
		dead_time = ts;
	}
	else{
		cout << ts << '\n';
		return 0;
	}
	//cout << "dead_time inicial: " << dead_time << endl;
	pair <ll, ll> ans; // <pos,wait_time>
	//cout << "ANS INICIAL: " << ans.f << " " << ans.s << endl;
	ans = {P[0]-1, ts - P[0] + 1};
	for(int i=0; i<N; i++){
		if(P[i] > dead_time && (tf-P[i] >= t)){
			cout << P[i]-1 << '\n';
			//cout << "ZERO DISTANCE IF " << endl;
			return 0;
		}
		ll wait_time = dead_time - P[i] + 1;
		dead_time+=t;
		//cout << "WAIT TIME FOR: " << i << ": " << wait_time << " ANS: " << ans.s << endl;
		if(wait_time < ans.s && (tf-P[i] >= t)){
			//cout << "if2OLD ANS: [" << ans.f << "," << ans.s << "]  ";
			ans = {P[i]-1, wait_time};
			//cout << "NEW ANS: [" << ans.f << "," << ans.s << "]" << endl;
		}
	}
	if(dead_time < tf-1 && (tf-dead_time >= t)) {
		//cout << "FINAL IF" << endl;
		cout << dead_time << '\n';
		return 0;
	}
	//cout << "dead_time final: " << dead_time << endl;
	cout << ans.f << '\n';
	return 0;
}