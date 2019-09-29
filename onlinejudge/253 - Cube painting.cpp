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

string next_horizontal(string s){
	char p1 = s[1];
	char p2 = s[2];
	char p3 = s[3];
	char p4 = s[4];
	s[1] = p3;
	s[2] = p1;
	s[3] = p4;
	s[4] = p2;
	return s;
}

string next_horizontal2(string s){
	char p0 = s[0];
	char p2 = s[2];
	char p3 = s[3];
	char p5 = s[5];
	s[0] = p3;
	s[2] = p0;
	s[3] = p5;
	s[5] = p2;
	return s;
}

string next_vertical(string s){
	char p0 = s[0];
	char p1 = s[1];
	char p4 = s[4];
	char p5 = s[5];
	s[0] = p4;
	s[1] = p0;
	s[4] = p5;
	s[5] = p1;
	return s;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	string s;
	while(cin>>s){
		string s1 = s.substr(0, 6);
		string s2 = s.substr(6, 6);
		bool equal = false;
		for(int i=0; i<4; i++){
			string saux = s1;
			for(int j=0; j<4; j++){
				string saux2 = saux;
				for(int k=0; k<4; k++){
					if(saux2 == s2)equal = true;
					saux2 = next_horizontal2(saux2);
				}
				saux = next_vertical(saux);
			}
			s1 = next_horizontal(s1);
		}
		if(equal) cout << "TRUE\n";
		else cout << "FALSE\n";
	}
	return 0;
}
