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
	int m, s, i;
	cin >> m >> s;
	int sum1 = s, sum2 = s;
	string bg(m, '0');
	string sm(m, '0');
	//check
	if(s>9*m || (s==0 && m>1)){
		cout << "-1 -1\n";
		return 0;
	}
	else if(s==0 && m==1){
		cout << "0 0\n";
		return 0;
	}
	//smallest
	sm[0] = '1'; sum1--;
	i = m-1;
	while(sum1>0){
		int dig = min(sum1, 9);
		sm[i] = sm[i] + dig;
		i--;
		sum1-=dig;
	}
	//biggest
	i = 0;
	while(sum2>0){
		int dig = min(sum2, 9);
		bg[i] = bg[i] + dig;
		i++;
		sum2-=dig;
	}
	cout << sm << ' ' << bg << '\n';
	return 0;
}
