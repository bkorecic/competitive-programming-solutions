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
	double l, w, h, theta;
	while(cin >> l >> w >> h  >> theta){
		theta = theta*(3.141592653/180.0); //Convertir a radianes
		double xd = l*tan(theta);
		if(xd<h){
			double areaTotal = l*h;
			double areaTriangulo = 0.5*l*xd;
			cout << fixed << setprecision(3) << w*(areaTotal-areaTriangulo) << " mL\n";
		}
		else{
			double areaTriangulo = 0.5*h*h*l/xd;
			cout << fixed << setprecision(3) << w*areaTriangulo << " mL\n";
		}
	}
	return 0;
}