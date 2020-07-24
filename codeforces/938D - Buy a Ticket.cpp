#include <bits/stdc++.h>
#define f first
#define s second
#define mp make_pair
#define pb push_back

typedef long long ll;

const ll INF = LLONG_MAX/2;

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m; cin >> n >> m;
    vector <vector <pair<ll,int>>> adj(n+1);
    for(int i=0; i<m; i++){
        int u, v; cin >> u >> v;
        ll w; cin >> w;
        u--; v--;
        adj[u].pb({2*w,v});
        adj[v].pb({2*w,u});
    }
    for(int i=0; i<n; i++){
        ll w; cin >> w;
        adj[n].pb({w, i});
    }

    vector <ll> dist(n+1, INF);
    priority_queue <pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> pq;
    pq.push({0, n});
    dist[n] = 0;
    while(!pq.empty()){
        ll d = pq.top().f;
        int u = pq.top().s;
        pq.pop();
        if(d > dist[u]) continue;
        for(auto v : adj[u]){
            if(dist[u] + v.first < dist[v.second]){
                dist[v.second] = dist[u] + v.first;
                pq.push({dist[v.second], v.second});
            }
        }
    }
    for(int i=0; i<n; i++){
        cout << dist[i] << " \n"[i == n-1];
    }
    return 0;
}
