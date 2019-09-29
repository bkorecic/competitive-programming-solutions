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

struct Point{
	ll x, y;
	Point() {x=y=0;}
	Point(ll _x, ll _y) : x(_x), y(_y) {}
	bool operator < (Point a, Point b) return a.x < b.x;
};

struct UnionFind {
	vii p;
	vi rank;
	const int N = 1e6+1;
	UnionFind() { rank.assign(N, 0);
	p.assign(N, {0,-1}); for (int i = 0; i < N; i++) p[i].f = i; }
	int findSet(int i) { return (p[i].f == i) ? i : (p[i].f = findSet(p[i].f)); }
	bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
	void unionSet(int i, int j) {
		if (!isSameSet(i, j)) {
			int x = findSet(i), y = findSet(j);
			if (rank[x] > rank[y]) p[y].f = x;
			else {
				p[x].f = y;
				if (rank[x] == rank[y]) rank[y]++; 
			}
		}
	}
};



int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int N, C;
	while(cin>>N>>C){
		UnionFind unionf();
		
		
		
		
		
	}
	return 0;
}
