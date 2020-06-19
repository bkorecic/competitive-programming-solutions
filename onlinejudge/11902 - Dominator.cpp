#include <bits/stdc++.h>
#define f first
#define s second
#define pb push_back
#define mp make_pair

typedef long long ll;

using namespace std;

vector <vector<int>> adj;
vector <vector<bool>> ans;
vector <bool> visited;

void dfs(int u){
    visited[u] = true;
    for(int v : adj[u]){
        if(!visited[v]){
            dfs(v);
        }
    }
}

void solve(int testcase){
    int n; cin >> n;
    adj.assign(n, vector<int>(0));
    ans.assign(n, vector<bool>(n, false));
    visited.assign(n, false);

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            int s; cin >> s;
            if(s == 1){
                adj[i].pb(j);
            }
        }
    }

    dfs(0);
    for(int i=0; i<n; i++){
        if(visited[i]){
            ans[0][i] = true; // reachable
            ans[i][i] = true; // dominates itself
        }
    }

    for(int i=1; i<n; i++){
        if(!ans[0][i]) continue; // if not reachable
        for(int j=1; j<n; j++){
            if(i==j) continue;
            visited.assign(n, false);
            visited[j] = true;
            dfs(0);
            if(!visited[i]){
                // j dominates i
                ans[j][i] = true;
            }
        }
    }

    cout << "Case " << testcase << ":\n";

    string separator = "+";
    for(int i=0; i<2*n-1; i++) separator += "-";
    separator += "+";

    for(int i=0; i<n; i++){
        cout << separator << '\n';
        cout << '|';
        for(int j=0; j<n; j++){
            if(ans[i][j] == true){
                cout << "Y|";
            }
            else cout << "N|";
        }
        cout << '\n';
    }
    cout << separator << '\n';

}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t; cin >> t;
    for(int i=1; i<=t; i++) solve(i);



    return 0;
}
