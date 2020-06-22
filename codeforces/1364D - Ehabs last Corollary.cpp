#include <bits/stdc++.h>
#define f first
#define s second
#define pb push_back
#define mp make_pair

typedef long long ll;

using namespace std;

int n, k, m;
vector <bool> visited;
vector <vector<int>> adj;
vector <int> ans;
stack <int> st;
vector <int> cycle;
bool done = false;
bool cycle_found = false;

void dfs(int u, int p=-1, int depth=0){
    //cout << "CUR VERTEX: " << u+1 << endl;
    visited[u] = true;
    st.push(u);
    if(depth%2==0) ans.pb(u);
    for(int v : adj[u]){
        if(done) return;
        if(v != p && visited[v]){
            // CYCLE
            cycle_found = true;
            //cout << "FOUND CYCLE " << u+1 << " RETURNS TO " << v+1 << endl;
            while(st.top() != v){
                cycle.pb(st.top());
                st.pop();
            }
            cycle.pb(st.top());
            done = true;
            return;
        }
        if(!visited[v] && ans.size() < k/2+k%2) dfs(v, u, depth+1);
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m >> k;

    visited.assign(n, false);
    adj.resize(n);

    for(int i=0; i<m; i++){
        int u, v; cin >> u >> v;
        u--; v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    dfs(1);

    if(ans.size() < k/2 + k%2 && !cycle_found){
        visited.assign(n, false);
        while(!st.empty()) st.pop();
        ans.clear();
        dfs(adj[1][0]);
    }
    if(!cycle_found){
        cout << 1 << '\n';
        for(int i=0; i<ans.size(); i++){
            cout << ans[i]+1 << " \n"[i==ans.size()-1];
        }
    }
    else{
        cout << 2 << '\n' << cycle.size() << '\n';
        for(int i=0; i<cycle.size(); i++){
            cout << cycle[i]+1 << " \n"[i==cycle.size()-1];
        }
    }
    return 0;
}
