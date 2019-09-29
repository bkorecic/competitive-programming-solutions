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
double dist(double ax, double ay, double bx, double by){
	return sqrt((ax-bx)*(ax-bx) + (ay-by)*(ay-by));
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int N; cin >> N;
	while(N--){
		double ax,ay,bx,by,cx,cy;
		cin>>ax>>ay>>bx>>by>>cx>>cy;
		double l1 = dist(ax,ay,bx,by);
		double l2 = dist(ax,ay,cx,cy);
		double l3 = dist(bx,by,cx,cy);
		double s = (l1+l2+l3)/2;
		double area = sqrt(s*(s-l1)*(s-l2)*(s-l3));
		int ans = round(area/7);
		cout << ans << '\n';
	}
	return 0;
}