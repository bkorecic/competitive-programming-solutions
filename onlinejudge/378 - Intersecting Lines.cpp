#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;

typedef pair<int, int> ii;

typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ii> vii;

#define mp make_pair
#define pb push_back
#define f first
#define s second

struct Point{
	double x, y;
	Point(){
		x = y = 0;
	}
	Point(double _x, double _y){
		x = _x;
		y = _y;
	}
};

struct Line{
	double a, b, c;
	Line(Point &p1, Point &p2){
		if(p2.x == p1.x){
			a = 1;
			b = 0;
			c = -p1.x;
		}
		else if(p1.y == p2.y){
			a = 0;
			b = 1;
			c = -p1.y;
		}
		else{
			double m = (p2.y - p1.y)/(p2.x - p1.x);
			a = 1;
			b = (-1)/m;
			c = (p2.y - m*p2.x)/m;
		}
	}
};

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int N; cin >> N;
	cout << "INTERSECTING LINES OUTPUT\n";
	for(int i=0; i<N; i++){
		double x1, y1, x2, y2, x3, y3, x4, y4;
		cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
		Point a(x1, y1);
		Point b(x2, y2);
		Point c(x3, y3);
		Point d(x4, y4);
		Line l1(a,b);
		Line l2(c,d);
		if(l1.a == l2.a && l1.b == l2.b && l1.c == l2.c){ //are equal
			cout << "LINE\n";
		}
		else if(l1.a == l2.a && l1.b == l2.b){ //are parallel
			cout << "NONE\n";
		}
		else{
			//cout << "l1: " << l1.a << ' ' << l1.b << ' ' << l1.c << '\n';
			//cout << "l2: " << l2.a << ' ' << l2.b << ' ' << l2.c << '\n';
			double y = (-l2.c + l1.c*(l2.a/l1.a))/(l2.b - l1.b*(l2.a/l1.a));
			double x = (-l1.c - l1.b*y)/l1.a;
			cout << fixed << setprecision(2) << "POINT " << x << ' ' << y << '\n';
		}
	}
	cout << "END OF OUTPUT\n";
	return 0;
}