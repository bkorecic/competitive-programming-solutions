#include <bits/stdc++.h>
#define EPS 1e-9
#define s second
#define f first
using namespace std;

typedef long long ll;

struct point { //Punto con lls
	ll x, y;
	point() {x = y = 0;}
	point(ll _x, ll _y) : x(_x), y(_y) {}
};

ll area(const vector<point> &P){
	ll result = 0.0, x1, y1, x2, y2;
	for(int i = 0; i < (int)P.size()-1; i++){
		x1 = P[i].x; x2 = P[i+1].x;
		y1 = P[i].y; y2 = P[i+1].y;
		result+=(x1*y2-x2*y1);
	}
return abs(result);
}

ll areaTriangulo(point a, point b, point c){
	vector <point> P;
	P.push_back(a);
	P.push_back(b);
	P.push_back(c);
	P.push_back(a);
	ll result = 0.0, x1, y1, x2, y2;
	for(int i = 0; i < (int)P.size()-1; i++){
		x1 = P[i].x; x2 = P[i+1].x;
		y1 = P[i].y; y2 = P[i+1].y;
		result+=(x1*y2-x2*y1);
	}
	return abs(result);
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int N; cin >> N;
	vector <point> poly;
	for(int i=0; i<N; i++){
		ll a,b; cin>>a>>b;
		point aux(a,b);
		poly.push_back(aux);
	}
	poly.push_back(poly[0]);
	pair <ll, ll> bestA = {0,0};
	ll areaTotal = area(poly);
	
	for(int i=0; i<poly.size()-1; i++){
		ll areaA = areaTriangulo(poly[i],poly[(i+1)%N],poly[(i+2)%N]);
		ll areaAnterior = areaA;
		int j = (i+2)%N;
		while(areaA < abs(areaTotal - areaA) && (j+1)%N != i){
			areaAnterior = areaA;
			areaA += areaTriangulo(poly[i], poly[j], poly[(j+1)%N]);
			j = (j+1)%N;
		}
		ll minimo = min(abs(areaTotal - 2*areaAnterior),abs(areaTotal - 2*areaA)); // T=Total, A= Area: abs((T-A) - A) = abs(T-2A)
		//cout << "MINIMO: " << minimo << endl;
		ll areaAuxiliar = min(areaAnterior, areaA); //El area auxiliar se guarda para luego tirarla al output
		if(minimo >= bestA.s) {
			bestA = {areaAuxiliar,minimo};
		}
	}
	//El mayor va primero:
	cout << max(bestA.f , areaTotal - bestA.f) << " " << min(bestA.f , areaTotal - bestA.f) << endl;
	return 0;
} 