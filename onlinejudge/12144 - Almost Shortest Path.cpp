#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;

typedef pair<int, int> ii;

typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ii> vii;

#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define INF 100000000
#define mp make_pair
#define pb push_back
#define f first
#define s second

void dijkstra(vector <vector <pair<int,int>>> &g, int start, vector<int> &dist) {
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
    q.push({0, start});
    dist[start] = 0;
    while (not q.empty()) {
        int priority = q.top().first, u = q.top().second;
        q.pop();
        if (priority != dist[u])
            continue;
        for (pair <int,int> p : g[u]) {
            int v = p.first, w = p.second;
            if(w==-1)continue;
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                q.push({dist[v], v});
            }
        }
    }
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int N, M;
	/* //test dijkstra
	vector <vector <pair<int,int>>> G(5);
	cin >> N;
	G[0].pb({1,2});
	G[0].pb({2,0});
	G[1].pb({2,2});
	G[2].pb({3,2});
	G[2].pb({4,1});
	G[3].pb({4,2});
	vector <int> dist(5, INF);
	dijkstra(G, 0, dist);
	cout << dist[N] << endl;
	*/
	while(cin >> N >> M, N!=0){
		int S, D; cin >> S >> D;
		vector <pair<pair<int,int>, int>> edges; //from,to,weight
		vector <vector <pair<int,int>>> G(N);
		vector <vector <pair<int,int>>> rG(N);
		for(int i=0; i<M; i++){
			int u, v, w;
			cin >> u >> v >> w;
			G[u].pb({v,w});
			rG[v].pb({u,w});
			edges.pb({{u,v},w});
		}
		vector <int> dist_G(N,INF);
		vector <int> dist_rG(N,INF);
		dijkstra(G, S, dist_G);
		dijkstra(rG, D, dist_rG);
		int minimo_inicial = dist_G[D];
		vector <vector <pair<int,int>>> final_G(N);
		/*
		cout << "EDGES: " << endl;
		for(pair <pair<int,int>, int> p : edges){
			cout << p.f.f << ' ' << p.f.s << ' ' << p.s << '\n';
		}
		
		cout << "####################\n";
		for(int i=0; i<G.size(); i++){
			cout << "Vecinos de " << i << ": ";
			for(pair <int,int> p : G[i]){
				cout << "(" << p.f << "," << p.s << ") ";
			}
			cout << endl;
		}
		
		*/
		for(int i=0; i<M; i++){
			int u = edges[i].f.f;
			int v = edges[i].f.s;
			int w = edges[i].s;
			int dist_1 = min(dist_G[u], dist_G[v]);
			int dist_2 = min(dist_rG[u], dist_rG[v]);
			if(dist_1 + w + dist_2 == minimo_inicial){
				w = -1;
			}
			final_G[u].pb({v,w});
		}
		//debug
		/*
		cout << "####################\n";
		for(int i=0; i<final_G.size(); i++){
			cout << "Vecinos de " << i << ": ";
			for(pair <int,int> p : final_G[i]){
				cout << "(" << p.f << "," << p.s << ") ";
			}
			cout << endl;
		} */
		//
		vector <int> dist_final(N,INF);
		dijkstra(final_G, S, dist_final);
		if(dist_final[D] == INF){
			cout << "-1\n";
		}
		else{
			cout << dist_final[D] << '\n';
		}
	}
	
	return 0;
}
