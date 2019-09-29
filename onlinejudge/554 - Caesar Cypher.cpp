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
	string line;
	map <string, int> dict;
	while(getline(cin,line), line != "#"){
		dict[line] = 1;
	}
	getline(cin,line);
	string aux;
	pair <int,string> ans = {0,""};
	int ansk = 0;
	for(int k=1; k<=26; k++){
		aux = line;
		for(int i=0; i<aux.length(); i++){
			if(aux[i] == ' ')aux[i] = (int)'A' + k - 1;
			else if((int)aux[i]+k == 'Z' + 1)aux[i] = ' ';
			else if((int)aux[i]+k > 'Z' + 1)aux[i] = 'A' + ((int)aux[i]+k - 'Z') - 2;
			else aux[i] = (int)aux[i]+k;
		}
		//count matches
		int matches = 0;
		string comp = "";
		aux += ' '; //para leer la última palabra
		for(int i=0; i<aux.length(); i++){
			if(aux[i] != ' '){
				comp += aux[i];
			}
			else{
				if(dict[comp] == 1)matches++;
				comp = "";
			}
		}
		if(matches >= ans.f){
			ans.f = matches;
			ans.s = aux;
			ansk = k;
		}
	}
	vector <string> r;
	string s = ans.s; 
	string comp = "";
	for(int i=0; i < s.length(); i++){
		if(s[i] != ' '){
				comp += s[i];
			}
		else{
			r.pb(comp);
			comp = "";
		}
	} 
	//cout answer
	int len = 0;
	for(int i=0; i<r.size(); i++){
		if(r[i]==""){} //nada
		else if(len+r[i].length() < 60){
			if(len!=0)cout << " " << r[i];
			else cout << r[i];
			len+=r[i].length()+1;
		}
		else if(len+r[i].length() == 60){
			cout << r[i] << '\n';
			//len+=r[i].length();
			len = 0;
		}
		else {
			cout << '\n' << r[i];
			len = r[i].length()+1;
		}
	} 
	cout << '\n';
	return 0;
}
