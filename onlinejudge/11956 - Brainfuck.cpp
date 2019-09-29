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

string convert(int a){
	stringstream stream;
	stream << hex << a;
	return stream.str();
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int T; cin >> T;
	for(int caso = 1; caso<=T; caso++){
		vector <int> mem (100,0);
		string s; cin >> s;
		int actual = 0;
		bool first = true;
		cout << "Case " << caso << ": ";
		for(int i=0; i<s.length(); i++){
			if(s[i] == '>'){
				actual = (actual+1)%100;
			}
			else if(s[i] == '<'){
				actual = (actual+99)%100;
			}
			else if(s[i] == '+'){
				mem[actual] = (mem[actual]+1)%256;
			}
			else if(s[i] == '-'){
				mem[actual] = (mem[actual]+255)%256;
			}
		}
		for(int i=0; i<mem.size();i++){
			string x = convert(mem[i]);
			for(int j=0; j<x.length(); j++){
				if(x[j] >= 'a' && x[j] <= 'z'){
					x[j] += 'A' - 'a';
				}
			}
			if(x.length()==1)x='0'+x;
			if(i==0)cout << x;
			else cout << ' ' << x;
		}
		cout << '\n';
	}
	return 0;
}
