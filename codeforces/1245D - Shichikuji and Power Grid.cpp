#include <bits/stdc++.h>
#define f first
#define s second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<pair<int,int>, ll> edge;

struct DSU{
    vector <int> parent;
    vector <int> sz;
    DSU(int n){
        parent.resize(n);
        sz.assign(n,1);
        for(int i=0; i<n; i++) parent[i] = i;
    }
    int find_set(int v){
        if(parent[v] == v) return v;
        return parent[v] = find_set(parent[v]); 
    }
    void union_set(int a, int b){
        a = find_set(a);
        b = find_set(b);
        if(a == b) return;
        if(sz[a] < sz[b]) swap(a,b);
        parent[b] = a;
        sz[a] += sz[b];
    }
};

bool comp(edge &a, edge &b){
    return a.s < b.s;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    vector <pii> coord(n);
    for(int i=0; i<n; i++){
        cin >> coord[i].f >> coord[i].s;
    }
    vector <ll> c(n);
    for(int i=0; i<n; i++) cin >> c[i];
    vector <ll> k(n);
    for(int i=0; i<n; i++) cin >> k[i];
    vector <vector<edge>> adj_list(n+1);
    vector <edge> edges;
    for(int i=0; i<n; i++){
        edges.push_back(mp(mp(n,i),c[i]));
    }
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            int xi = coord[i].f, yi = coord[i].s;
            int xj = coord[j].f, yj = coord[j].s;
            ll cost = (abs(xi-xj)+abs(yi-yj))*(k[i]+k[j]);
            edges.push_back(mp(mp(i,j), cost));
        }
    }
    // kruskal MST
    sort(edges.begin(), edges.end(), comp);
    vector <pii> connect;
    vector <int> station;
    DSU dsu(n+1);
    ll ans = 0;
    for(int i=0; i<edges.size(); i++){
        int a = edges[i].f.f, b = edges[i].f.s;
        if(dsu.find_set(a) != dsu.find_set(b)){
            dsu.union_set(a,b);
            ans += edges[i].s;
            if(a != n && b != n) connect.pb(mp(a,b));
            else{
                station.pb(min(a,b));
            }
        }
    }
    cout << ans << '\n';
    cout << station.size() << '\n';
    for(int i=0; i<station.size(); i++){
        cout << station[i]+1 << " \n"[i==station.size()-1];
    }
    cout << connect.size() << '\n';
    for(int i=0; i<connect.size(); i++){
        cout << connect[i].f+1  << ' ' << connect[i].s+1 << '\n';
    }
    return 0;
}
