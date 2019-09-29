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

ll area(vector<point> P){
	P.push_back(P[0]);
	ll result = 0.0, x1, y1, x2, y2;
	for(int i = 0; i < (int)P.size()-1; i++){
		x1 = P[i].x; x2 = P[i+1].x;
		y1 = P[i].y; y2 = P[i+1].y;
		result+=(x1*y2-x2*y1);
	}
return abs(result);
}

ll areaTriangulo(point p1, point p2, point p3){
	return abs((p1.x*p2.y - p1.y*p2.x) + (p2.x*p3.y - p2.y*p3.x) + (p3.x*p1.y - p3.y*p1.x));
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int N; cin >> N;
	vector <point> P;
	for(int i=0; i<N; i++){
		ll a,b; cin>>a>>b;
		point aux(a,b);
		P.push_back(aux);
	}
	ll area_total = area(P);
	//Double-Pointer:
	int j = 1;
	ll ans = 0;
	ll area_left = 0;
	ll area_right;
	ll area_left_last = 0;
	for(int i=0; i<N; i++){
		if(area_left != 0) area_left = area_left_last - areaTriangulo(P[(i+N-1)%N], P[i], P[j]);
		while(1){
			area_left_last = area_left;
			area_left += areaTriangulo(P[i], P[j], P[(j+1)%N]);
			area_right = area_total - area_left;
			if(area_left >= area_right) break;
			j = (j+1)%N;
		}
		ans = max(ans, min(area_left , area_total - area_left_last));
	}
	cout << max(ans, area_total - ans) << " " << min(ans, area_total - ans) << '\n';
	return 0;
} 
