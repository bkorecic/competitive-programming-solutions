#include <bits/stdc++.h>
#define f first
#define s second
#define pb push_back
#define mp make_pair
 
using namespace std;
 
typedef long long ll;
 
struct DSU{
    int n;
    vector <int> parent;
    vector <int> sz;
    DSU(int _n){
        n = _n;
        parent.resize(n);
        for(int i=0; i<n; i++) parent[i] = i;
        sz.assign(n,1);
    }
    int find_set(int v){
        if(parent[v] == v) return v;
        return parent[v] = find_set(parent[v]); 
    }
    void union_set(int a, int b){
        a = find_set(a);
        b = find_set(b);
        if(a != b){
            if(sz[a] < sz[b]) swap(a,b);
            parent[b] = a;
            sz[a] += sz[b];
        } 
    }
};
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m; cin >> n >> m;
    vector <set<int>> adj_list(n);
    for(int i=0; i<m; i++){
        int u, v; cin >> u >> v;
        u--; v--;
        adj_list[u].insert(v);
        adj_list[v].insert(u);
    }
    int par = -1;
    vector <bool> ignore(n);
    DSU dsu(n);
    for(int i=0; i<n; i++){
        if(adj_list[i].size() < n/2){
            if(par == -1) par = i;
            else{
                dsu.union_set(par, i);  
            }
            ignore[i] = true;
        }
    }
    for(int i=0; i<n; i++){
        if(ignore[i]) continue;
        for(int j=0; j<n; j++){
            if(j==i) continue;
            if(adj_list[i].find(j) == adj_list[i].end()){
                dsu.union_set(i,j); 
            }
        }
    }
    int ans = 0;
    for(int i=0; i<n; i++){
        if(dsu.parent[i] == i) ans++;
    }
    cout << ans-1 << '\n';
    return 0;
}
