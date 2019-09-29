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
	double a,b,c;
	while(cin >> a >> b >> c){
		double semi = (a+b+c)/2;
		double Atri = sqrt(semi*(semi-a)*(semi-b)*(semi-c));
		
		double R = (a*b*c)/(4.0*Atri);
		double Amayor = (acos(-1))*R*R;
		
		double r = (2.0*Atri)/(a+b+c);
		double Amenor = (acos(-1))*r*r;
		
		cout << fixed << setprecision(4) << Amayor - Atri << ' ' << Atri - Amenor << ' ' << Amenor << '\n';
		
	}
	
	
	
	return 0;
}
