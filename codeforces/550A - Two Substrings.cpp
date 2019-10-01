#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;

typedef pair<int, int> ii;

typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ii> vii;

#define mp make_pair
#define pb push_back
#define f first
#define s second
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	string s; cin >> s;
	int n = s.length();
	vector <int> AB;
	vector <int> BA;
	for(int i=0; i<n-1; i++){
		if(s[i] == 'A' && s[i+1] == 'B')AB.pb(i);
		if(s[i] == 'B' && s[i+1] == 'A')BA.pb(i);
	}
	sort(AB.begin(), AB.end()); sort(BA.begin(), BA.end());
	bool possible = false;
	if(AB.size() == 0 or BA.size() == 0){
		cout << "NO\n"; return 0;
	}
	if(abs(AB[0] - BA[BA.size()-1]) > 1) possible = true;
	if(abs(BA[0] - AB[AB.size()-1]) > 1) possible = true;
	if(possible) cout << "YES\n";
	else cout << "NO\n";
	return 0;
}
