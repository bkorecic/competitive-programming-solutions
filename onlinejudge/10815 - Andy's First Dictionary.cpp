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
	ios_base::sync_with_stdio(0); cin.tie(0);
	string s;
	vector <string> dictionary;
	map <string, int> check;
	string line;
	while(getline(cin,line)){
		for(int i=0; i<line.length(); i++){
			if(line[i] >= 'A' && line[i] <= 'Z'){
				line[i] = line[i] + 'a' - 'A';
			}
		}
		for(int i=0; i<line.length(); i++){
			string s = "";
			if(line[i] >= 'a' && line[i] <= 'z'){
				while(line[i] >= 'a' && line[i] <= 'z'){
					s = s + line[i];
					i++;
				}
				if(s.length()>0 && check[s] == 0){
					dictionary.pb(s);
					check[s] = 1;
				}
			}
		}
	}
	sort(dictionary.begin(),dictionary.end());
	for(int i=0; i < dictionary.size(); i++){
		cout << dictionary[i] << endl;
	}
	return 0;
}
