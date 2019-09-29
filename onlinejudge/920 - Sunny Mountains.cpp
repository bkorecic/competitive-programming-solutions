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

bool pairSort(pair <int,int> a, pair<int,int> b){
	return a.f<b.f;
}

bool pairSort2(pair <pair <int,int>, int> a, pair <pair <int,int>, int> b){
	return a.f.f < b.f.f;
}

int main(){
	//messy code :-(
	ios_base::sync_with_stdio(0); cin.tie(0);
	int T; cin >> T;
	for(int rep = 0; rep<T; rep++){
		int N; cin >> N;
		int parity = 1;
		if(N%2==0)parity=0;
		vector <pair <int, int> > points(N);
		for(int i=0; i<N; i++){
			int a,b; cin >> a >> b;
			points[i] = {a,b};
		}
		sort(points.begin(),points.end(),pairSort);
		if(points[0].s >= points[1].s) parity = 0;
		vector <pair <pair <int,int>, int>> heights;
		int H = points[N-2].s;
		heights.push_back({points[N-2], N-2});
		for(int i=N-1; i>=0; i--){
			if(points[i].s > H && i%2 == parity){
				heights.push_back({points[i], i});
				H = points[i].s;
			}
		}
		sort(heights.begin(),heights.end(),pairSort2);
		double lastH = 0;
		double ans = 0;
		for(int i=heights.size()-1; i>=0; i--){
			double currentH = heights[i].f.s;
			int index = heights[i].s;
			double h = currentH - lastH;
			double dx = points[index+1].f - points[index].f;
			double Hg = points[index].s - points[index+1].s;
			if(Hg==0)continue;
			double d = sqrt(Hg*Hg + dx*dx);
			ans += d*h/Hg;
			lastH = currentH;
		}
		cout << fixed << setprecision(2) << ans << '\n';
	}
	return 0;
}
