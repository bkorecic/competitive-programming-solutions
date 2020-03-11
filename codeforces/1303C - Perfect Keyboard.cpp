#include <bits/stdc++.h>
#define f first
#define s second
#define pb push_back
 
using namespace std;
 
typedef long long ll;
 
const int ALPH = 'z'-'a'+1;
 
void dfs(int u, vector<set<int>> &adj, vector<bool> &visited){
    visited[u] = true;
    char print = 'a' + u;
    cout << print;
    for(int v : adj[u]){
        if(!visited[v]) dfs(v, adj, visited);
    }
}
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while(t--){
        string s; cin >> s;
        vector <set<int>> adj(ALPH);
        int n = s.size();
        for(int i=0; i<n-1; i++){
            adj[s[i]-'a'].insert(s[i+1]-'a');
            adj[s[i+1]-'a'].insert(s[i]-'a');
        }
        int one_adj = 0;
        int leaf;
        bool line = true;
        for(int i=0; i<ALPH; i++){
            if(adj[i].size() > 2) line = false;
            if(adj[i].size() == 1){
                one_adj++;
                leaf = i;
            }
        }
        if(n == 1){
            cout << "YES\n";
            for(int i=0; i<ALPH; i++){
                char c = 'a' + i;
                cout << c;
            } cout << '\n';
        }
        else if(line && one_adj == 2){
            cout << "YES\n";
            vector <bool> visited(n, false);
            dfs(leaf, adj, visited);
            for(int i=0; i<ALPH; i++){
                if(!visited[i]){
                    char c = 'a'+i;
                    cout << c;
                }
            }
            cout << '\n';
        }
        else{
            cout << "NO\n";
        }
    }
 
    return 0;
}
