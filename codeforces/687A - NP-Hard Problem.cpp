#include <bits/stdc++.h>
#define f first
#define s second
#define mp make_pair
#define pb push_back

typedef long long ll;

using namespace std;

vector <int> A, B;
vector <vector<int>> adj;
vector <bool> visited;
vector <int> color;
bool bipartite = true;

void dfs(int u, int c=0){
    visited[u] = true;
    color[u] = c;
    if(c == 0) A.pb(u);
    else B.pb(u);

    for(int v : adj[u]){
        if(visited[v] && color[v] == c) bipartite=false;
        if(!visited[v])
            dfs(v, 1-c);
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m; cin >> n >> m;
    visited.assign(n, false);
    adj.resize(n);
    color.assign(n, -1);
    for(int i=0; i<m; i++){
        int u, v; cin >> u >> v;
        u--; v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    for(int i=0; i<n; i++){
        if(!visited[i]) dfs(i);
    }
    if(!bipartite){
        cout << -1 << '\n';
        return 0;
    }
    cout << A.size() << '\n';
    for(int i=0; i<A.size(); i++){
        cout << A[i]+1 << " \n"[i==A.size()-1];
    }
    cout << B.size() << '\n';
    for(int i=0; i<B.size(); i++){
        cout << B[i]+1 << " \n"[i==B.size()-1];
    }
    return 0;
}
