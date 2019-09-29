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
	string s,t; cin >> s >> t;
	int len_s = s.length(), len_t = t.length();
	vector <int> count_s(30,0);
	vector <int> count_t(30,0);
	for(int i=0; i<len_s; i++)count_s[s[i] - 'a']++;
	for(int i=0; i<len_t; i++)count_t[t[i] - 'a']++;
	bool allequal = true, samelen = (len_s == len_t);
	bool pos = (len_s >= len_t), isSubsequence = false;
	for(int i=0; i<30; i++){
		if(count_s[i] != count_t[i])allequal=false;
		if(count_s[i] < count_t[i])pos=false;
	}
	int i = 0;
	for(int j=0; j<len_s; j++){
		if(s[j] == t[i] && i < len_t)i++;
	}
	if(i>=len_t-1)isSubsequence = true;
	if(pos){
		if(samelen && allequal)cout << "array\n";
		else if(isSubsequence)cout << "automaton\n";
		else cout << "both\n";
	}
	else cout << "need tree\n";
	return 0;
}
