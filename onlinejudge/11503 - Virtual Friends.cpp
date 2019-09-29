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

struct UnionFind {
	vi p, rank, tam;
	UnionFind(int N) { rank.assign(N, 0);
	tam.assign(N,1);
	p.assign(N, 0); for (int i = 0; i < N; i++) p[i] = i; }
	int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
	bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
	void unionSet(int i, int j) {
		if (!isSameSet(i, j)) { 
			int x = findSet(i), y = findSet(j);
			int s1 = tam[x], s2 = tam[y];
			if (rank[x] > rank[y]) {
				p[y] = x;
				tam[x] += tam[y];
			}
			else {
				p[x] = y;
				tam[y] += tam[x];
				if (rank[x] == rank[y]) rank[y]++; 
			}
		} 
	} 
};

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int T; cin >> T;
	for(int rep = 0; rep < T; rep++){
		map <string,int> indexing;
		int F; cin >> F;
		int nameIndex = 1;
		UnionFind G(200001);
		for(int i=0; i<F; i++){
			string a,b; cin >> a >> b;
			if(indexing[a] == 0){
				indexing[a] = nameIndex;
				nameIndex++;
			}
			if(indexing[b] == 0){
				indexing[b] = nameIndex;
				nameIndex++;
			}
			G.unionSet(indexing[a],indexing[b]);
			cout << G.tam[G.findSet(indexing[a])] << '\n';			
		}
	}
	
	
	
	return 0;
}
