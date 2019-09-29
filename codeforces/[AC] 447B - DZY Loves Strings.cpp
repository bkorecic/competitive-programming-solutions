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

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	string s; cin >> s;
	int len = s.length();
	int k; cin >> k;
	int wm = -1;
	vector <int> w(26);
	for(int i=0; i<26; i++){
		cin >> w[i];
		if(w[i]>wm)wm=w[i];
	}
	//initial value
	int val = 0;
	for(int i=1; i<=len; i++){
		val += w[s[i-1]-'a']*i;
	}
	for(int i=0; i<k; i++){
		val += wm*(len+1+i);
	}
	cout << val << '\n';
	
	return 0;
}
