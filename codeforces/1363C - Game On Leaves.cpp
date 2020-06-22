#include <bits/stdc++.h>
#define f first
#define s second
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;

vector <vector<int>> adj_list;
vector <int> dist;

void dfs(int u, int depth=0){
    dist[u] = depth;
    for(int v : adj_list[u]){
        if(dist[v] == -1){
            dfs(v, depth+1);
        }
    }
}

void solve(){
    int n, x; cin >> n >> x;
    x--;
    adj_list.assign(n, vector<int>(0));
    dist.assign(n, -1);
    for(int i=0; i<n-1; i++){
        int u, v; cin >> u >> v;
        u--; v--;
        adj_list[u].pb(v);
        adj_list[v].pb(u);
    }
    dfs(x);
    int cnt = 0;
    for(int i=0; i<n; i++){
        if(dist[i]>0) cnt++;
    }
    if(adj_list[x].size() <= 1) cnt = 1; // x is leaf case
    if(cnt%2 == 0)
        cout << "Ashish\n";
    else
        cout << "Ayush\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while(t--) solve();

    return 0;
}
