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
	int ans = -1;
	for(int i=0; i<len;i++){
		if((s[i]-'0')%2==0 && s[i] < s[len-1]){
			swap(s[i], s[len-1]);
			cout << s << '\n';
			return 0;
		}
	}
	for(int i=len-1; i>=0;i--){
		if((s[i]-'0')%2==0 && s[i] > s[len-1]){
			swap(s[i], s[len-1]);
			cout << s << '\n';
			return 0;
		}
	}
	cout << -1 << '\n';
	return 0;
}
