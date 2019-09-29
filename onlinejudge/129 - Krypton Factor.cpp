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

int contador;
size_t N;
int L;
bool done;
string ans;

bool check(string &s){
	int len = s.length();
	int size = 1;
	for(int j = len-2; j>=0; j-=2){
		string s1 = s.substr(j, size);
		string s2 = s.substr(j+size, size);
		//cout << "COMPARANDO: " << s1 << " CON " << s2 << '\n';
		if(s1 == s2) return false;
		size++;
	}
	return true;
}


void build(string s = ""){
	if(done)return;
	if(contador == N){
		ans = s;
		done = true;
		return;
	}
	for(int i=0; i<L; i++){
		char pick = (char)('A' + i);
		string candidate = s + pick;
		if(check(candidate)){
			contador++;
			build(candidate);
		 }
	}
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	while(cin >> N >> L, N != 0){
		done = false;
		contador = 0;
		build();
		//output format
		int groupCount = 0;
		int lineCount = 0;
		for(size_t i=0; i<ans.length(); i++){
			if(lineCount == 64){
				cout << '\n';
				lineCount = 0;
				groupCount = 0;
			}
			if(groupCount == 4){
				cout << ' ';
				groupCount = 0;
			}
			cout << ans[i];
			groupCount++;
			lineCount++;
		}
		cout << '\n' << ans.length() << '\n';
	}
	return 0;
}
