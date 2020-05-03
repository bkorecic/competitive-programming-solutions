#include <bits/stdc++.h>
#define f first
#define s second
#define pb push_back
 
using namespace std;
 
typedef long long ll;
 
vector <vector<int>> adj_list;
vector <bool> visited;
vector <int> n_child;
vector <int> dist;
 
void calc_child(int u){
    visited[u] = true;
    int total_child = 0;
    for(int v : adj_list[u]){
        if(visited[v]) continue;
        calc_child(v); 
        total_child += 1 + n_child[v];
    }
    n_child[u] = total_child;
}
 
void dfs(int u, int depth=0){
    dist[u] = depth;
    visited[u] = true;
    for(int v : adj_list[u]){
        if(visited[v]) continue;
        dfs(v, depth+1);
    }
}
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, k; cin >> n >> k;
    adj_list.resize(n);
    visited.assign(n, false);
    n_child.assign(n, 0);
    dist.assign(n, 0);
    for(int i=0; i<n-1; i++){
        int u, v; cin >> u >> v;
        u--; v--;
        adj_list[u].pb(v);
        adj_list[v].pb(u);
    }
    calc_child(0);
    visited.assign(n, false);
    dfs(0);
    vector <int> val(n,0);
    for(int i=0; i<n; i++){
        val[i] = dist[i] - n_child[i];
    }
    sort(val.begin(), val.end(), greater<int>());
    ll ans = 0;
    for(int i=0; i<k; i++){
        ans += val[i];
    }
    cout << ans << '\n';
    return 0;
}