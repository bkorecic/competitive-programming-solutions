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
	int N;
	int caso = 1;
	while(cin >> N, N!=0){
		double x1, y1, x2, y2, x3, y3;
		cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
		double h, k;
		//CALCULAR CENTRO CIRCUNFERENCIA
		h = ((x1*x1+y1*y1)*(y2-y3) + (x2*x2+y2*y2)*(y3-y1) + (x3*x3 + y3*y3)*(y1-y2))/(2*(x1*(y2-y3) - y1*(x2-x3) + x2*y3 - x3*y2)); 
		k = ((x1*x1+y1*y1)*(x3-x2) + (x2*x2+y2*y2)*(x1-x3) + (x3*x3 + y3*y3)*(x2-x1))/(2*(x1*(y2-y3) - y1*(x2-x3) + x2*y3 - x3*y2));    
		//Centro (h,k)
		//CALCULAR TODOS LOS VERTICES
		double theta = (2*acos(-1)/N); //ANGULO CENTRAL
		double costheta = cos(theta);
		double sintheta = sin(theta);
		vector <pair <double,double> > vertices(N);
		vertices[0] = mp(x1,y1);
		double ax = x1, ay = y1; //pts actuales
		for(int i=1; i<=N-1; i++){
			ax = ax-h;
			ay = ay-k;
			//Rotar con ángulo theta
			double ax2 = ax*costheta - ay*sintheta;
			double ay2 = ax*sintheta + ay*costheta;
			ax = ax2+h;
			ay = ay2+k;
			vertices[i] = mp(ax,ay);
		}
		double minx = x1, maxx = x1, miny = y1, maxy = y1;
		for(int i=0; i<N; i++){
			if(vertices[i].f < minx)minx = vertices[i].f;
			if(vertices[i].f > maxx)maxx = vertices[i].f;
			if(vertices[i].s < miny)miny = vertices[i].s;
			if(vertices[i].s > maxy)maxy = vertices[i].s;
		}
		cout << fixed << setprecision(3) << "Polygon " << caso << ": " << (maxx-minx)*(maxy-miny) << '\n';
		caso++;
	}
	
	
	
	return 0;
}
