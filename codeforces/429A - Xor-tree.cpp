#include <bits/stdc++.h>
#define f first
#define s second
#define mp make_pair
#define pb push_back

typedef long long ll;

using namespace std;

vector <vector<int>> adj;
vector <bool> visited;
vector <bool> needs_flip;
vector <int> ans;

void dfs(int u, int d=0, bool even_f=0, bool odd_f=0){
    visited[u] = true;
    bool f=false;
    if(d%2==0){
        if((needs_flip[u]^even_f) == 1){
            even_f = !even_f;
            ans.pb(u);
        }
    }
    else{
        if((needs_flip[u]^odd_f) == 1){
            odd_f = !odd_f;
            ans.pb(u);
        }
    }
    for(int v : adj[u]){
        if(!visited[v]) dfs(v, d+1, even_f, odd_f);
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    adj.resize(n);
    visited.assign(n, false);
    needs_flip.assign(n, false);
    for(int i=0; i<n-1; i++){
        int u, v; cin >> u >> v;
        u--; v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    vector <int> state(n);
    for(int i=0; i<n; i++){
        cin >> state[i];
    }
    for(int i=0; i<n; i++){
        int s; cin >> s;
        if(s != state[i]) needs_flip[i] = true;
    }
    dfs(0);
    cout << ans.size() << '\n';
    for(int u : ans){
        cout << u+1 << '\n';
    }
    return 0;
}
