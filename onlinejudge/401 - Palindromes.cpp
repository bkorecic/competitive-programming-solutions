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

map <char,char> mirrors;

string mirror(string x){
	for(int i=0; i<x.length(); i++){
		x[i] = mirrors[x[i]];
	}
	return x;
}

bool isPalindrome(string x){
	int len = x.length();
	for(int i=0; i<len/2; i++) if(x[i] != x[len-1-i])return false;
	return true;
}

bool isMirrored(string x){
	string x2 = mirror(x);
	int len = x.length();
	for(int i=0; i<len; i++) if(x[i] != x2[len-1-i]) return false;
	return true;
}

bool hasMirror(string x){
	for(int i=0; i<x.length(); i++) if(mirrors[x[i]] == '\0') return false;
	return true;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	mirrors['A'] = 'A';		mirrors['E'] = '3';
	mirrors['H'] = 'H';		mirrors['I'] = 'I';
	mirrors['J'] = 'L';		mirrors['L'] = 'J';
	mirrors['M'] = 'M';		mirrors['O'] = 'O';
	mirrors['S'] = '2';		mirrors['T'] = 'T';
	mirrors['U'] = 'U';		mirrors['V'] = 'V';
	mirrors['W'] = 'W';		mirrors['X'] = 'X';
	mirrors['Y'] = 'Y';		mirrors['Z'] = '5';
	mirrors['1'] = '1';		mirrors['2'] = 'S';
	mirrors['3'] = 'E';		mirrors['5'] = 'Z';
	mirrors['8'] = '8';
	
	string s;
	while(cin >> s){
		bool pal = false;
		bool mirrored = false;
		//cout << "HAS MIRROR: " << hasMirror(s) << endl;
		//cout << "IS MIRRORED: " << isMirrored(s) << endl;
		//cout << "MIRROR: " << mirror(s) << endl;
		if(hasMirror(s) && isMirrored(s)) mirrored = true;
		if(isPalindrome(s)) pal = true;
		
		if(pal == false && mirrored == false){
			cout << s << " -- is not a palindrome." << endl;
		}
		
		else if(pal == true && mirrored == false){
			cout << s << " -- is a regular palindrome." << endl;
		}
		
		else if(pal == false && mirrored == true){
			cout << s << " -- is a mirrored string." << endl;
		}
		
		else if(pal == true && mirrored == true){
			cout << s << " -- is a mirrored palindrome." << endl;
		}
		cout << endl;
	}
	
	return 0;
}
