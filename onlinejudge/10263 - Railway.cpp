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
#define EPS 1e-9
#define INF 1e9
#define PI acos(-1.0)

double degToRad(double d) {
	return d * PI / 180.0;
}
double radToDeg(double r) {
	return r * 180.0 / PI;
}

struct point {
	double x, y;
	point() {
		x = INF, y = INF;
	}
	point(double _x, double _y) {
		x = _x, y = _y;
	}
	bool operator <(point other) const {
		if (fabs(x - other.x) > EPS)
			return x < other.x;
		return y < other.y;
	}
};

double dist(point p1, point p2) {
	return hypot(p1.x - p2.x, p1.y - p2.y);
}

struct line {
	double a, b, c;
};

void pointsToLine(point p1, point p2, line &l) {
	if (fabs(p1.x - p2.x) < EPS) // vertical line
		l.a = 1.0, l.b = 0.0, l.c = -p1.x;
	else {
		l.a = -(double) (p1.y - p2.y) / (p1.x - p2.x);
		l.b = 1.0;
		l.c = -(double) (l.a * p1.x) - p1.y;
	}
}

struct vec {
	double x, y;
	vec(double _x, double _y) {
		x = _x, y = _y;
	}
};

vec toVector(point p1, point p2) {
	return vec(p2.x - p1.x, p2.y - p1.y);
}

vec scaleVector(vec v, double s) {
	return vec(v.x * s, v.y * s);
}

point translate(point p, vec v) {
	return point(p.x + v.x, p.y + v.y);
}

double dot(vec a, vec b) {
	return (a.x * b.x + a.y * b.y);
}

double norm_sq(vec v) {
	return v.x * v.x + v.y * v.y;
}

double distToLine(point p, point A, point B, point &c) {
	vec Ap = toVector(A, p), AB = toVector(A, B);
	double u = dot(Ap, AB) / norm_sq(AB);
	c = translate(A, scaleVector(AB, u));
	return dist(p, c);
}

double distToLineSegment(point p, point A, point B, point &c) {
	vec Ap = toVector(A, p), AB = toVector(A, B);
	double u = dot(Ap, AB) / norm_sq(AB);
	if (u < 0.0) {
		c = point(A.x, A.y);
		return dist(p, A);
	}
	if (u > 1.0) {
		c = point(B.x, B.y);
		return dist(p, B);
	}
	return distToLine(p, A, B, c);
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	double X, Y;
	while(cin >> X >> Y){
		point p(X,Y);
		int N; cin >> N;
		point def;
		pair <double, point> ans = {1e9, def};
		vector <point> segment(N+1);
		for(int i=0; i<N+1; i++){
			double aux1, aux2;
			cin >> aux1 >> aux2;
			point aux3(aux1,aux2);
			segment[i] = aux3;
		}
		for(int i=0; i<N; i++){
			point a = segment[i]; point b = segment[i+1];
			point c;
			double dist = distToLineSegment(p,a,b,c);
			if(dist < ans.f){
				ans = {dist, c};
				//cout << "NEW ANS: " << dist << "  WITH POINT: " << c.x << " " << c.y << endl;
			}
		}
		if(N==0){
			cout << fixed << setprecision(4) << segment[0].x << '\n' << segment[0].y << '\n';
		}
		else{
			cout << fixed << setprecision(4) << ans.s.x << '\n' << ans.s.y << '\n';
		}
	}
	return 0;
}
