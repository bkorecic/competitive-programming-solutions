#include <bits/stdc++.h>
#define f first
#define s second
#define pb push_back
 
using namespace std;
 
typedef long long ll;
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m; cin >> n >> m;
    vector <pair<ll,int>> v_ind(n);
    vector <ll> cost(n, 0);
    vector <vector<int>> adj(n);
    for(int i=0; i<n; i++){
        cin >> v_ind[i].f;
        v_ind[i].s = i;
    }
    for(int i=0; i<m; i++){
        int u, v; cin >> u >> v;
        u--; v--;
        adj[u].pb(v);
        adj[v].pb(u);
        cost[u] += v_ind[v].f;
        cost[v] += v_ind[u].f;
    }
    sort(v_ind.begin(), v_ind.end(), greater<pair<ll,int>>());
    ll ans = 0;
    for(int i=0; i<n; i++){
        int u = v_ind[i].s;
        ans += cost[u];
        for(int v : adj[u]){
            cost[v] -= v_ind[i].f;
        }
    }
    cout << ans << '\n';
    return 0;
}
