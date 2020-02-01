#include <bits/stdc++.h>
#define f first
#define s second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

struct LCA{
    int n, l, timer=0;
    vector <vector<int>> up;
    vector <int> enter, exit;
    LCA(vector <vector<int>> &adj, int root=0){
        n = adj.size();
        l = ceil(log2(n));
        enter.resize(n);
        exit.resize(n);
        up.resize(n, vector<int>(l+1));
        dfs(root, root, adj);
    }

    void dfs(int u, int p, vector<vector<int>> &adj){
        enter[u] = timer++;
        up[u][0] = p;
        for(int j=1; j<=l; j++){
            up[u][j] = up[up[u][j-1]][j-1]; 
        }
        for(int v : adj[u]){
            if(v != p) dfs(v, u, adj);
        }
        exit[u] = timer++;
    }

    bool is_ancestor(int u, int v){ // v is ancestor of u
        return enter[u] <= enter[v] && exit[u] >= exit[v]; 
    }

    int query(int u, int v){
        if(is_ancestor(u,v)) return u;
        if(is_ancestor(v,u)) return v;
        for(int i=l; i>=0; i--){
            if(!is_ancestor(up[u][i], v)){
                u = up[u][i]; 
            }
        }
        return up[u][0];
    } 
};

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    for(int testcase = 1; testcase <= t; testcase++){
        int n; cin >> n;
        vector <vector<int>> adj(n);
        for(int i=0; i<n; i++){
            int m; cin >> m;
            for(int j=0; j<m; j++){
                int u; cin >> u;
                u--;
                adj[i].pb(u);
            }
        }
        LCA lca(adj);
        int q; cin >> q;
        cout << "Case " << testcase << ":\n";
        for(int i=0; i<q; i++){
            int u, v; cin >> u >> v;
            u--; v--;
            cout << lca.query(u, v)+1 << '\n';
        }
    }
    return 0;
}
