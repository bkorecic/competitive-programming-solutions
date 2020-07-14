#include <bits/stdc++.h>
#define f first
#define s second
#define mp make_pair
#define pb push_back

typedef long long ll;

using namespace std;

struct Edge{
    int a, b, cost;
    Edge(int _a, int _b, int _cost) : a(_a), b(_b), cost(_cost) {}
};

int n, m;
vector<Edge> edges;
const int INF = 1000000000;

int bellman_ford(int u, int v){
    vector<int> d (n, INF);
    d[u] = 0;
    for (int i=0; i<n-1; ++i)
        for (int j=0; j<m; ++j)
            if (d[edges[j].a] < INF)
                d[edges[j].b] = min (d[edges[j].b], d[edges[j].a] + edges[j].cost);
    return d[v];
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int d; cin >> n >> d;
    vector <int> a(n);
    vector <pair<int,int>> coord(n);
    for(int i=1; i<n-1; i++) cin >> a[i];
    for(int i=0; i<n; i++) cin >> coord[i].f >> coord[i].s;

    a[0] = 0;
    a[n-1] = 0;
    for(int i=0; i<n; i++){
        // in -> out
        edges.pb(Edge(i, i+n, -a[i]));
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i == j) continue;
            int dist = abs(coord[i].f - coord[j].f)
                + abs(coord[i].s - coord[j].s);
            edges.pb(Edge(i+n, j, d*dist));
        }
    }
    n = 2*n;
    m = edges.size();
    cout << bellman_ford(0, n-1) << '\n';
    return 0;
}
