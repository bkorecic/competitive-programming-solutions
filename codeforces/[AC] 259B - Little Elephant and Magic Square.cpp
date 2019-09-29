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
	int a1, a2, a3, a4, a5, a6, g;
	cin >> g >> a1 >> a2 >> a3 >> g >> a4 >> a5 >> a6 >> g;
	int s = a2+a5;
	for(int a=1; a<a2+a5; a++){
		int b = a2+a5-a;
		if(a+a1+a2 == a+a3+a5 && b+a2+a4 == b+a5+a6 && a+a1+a2 == b+a2+a4){
			int y = a+a2-a6;
			cout << a << ' ' << a1 << ' ' << a2 << '\n';
			cout << a3 << ' ' << y << ' ' << a4 << '\n';
			cout << a5 << ' ' << a6 << ' ' << b << '\n';
		}
	}
	return 0;
}
