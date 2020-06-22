#include <bits/stdc++.h>
#define f first
#define s second
#define mp make_pair
#define pb push_back
 
using namespace std;
 
typedef long long ll;
 
set <pair<int,int>> dom = {{0,0}, {0,1}, {0,2}, {0,3}, {0,4}, {0,5},
                            {1,1}, {1,2}, {1,3}, {1,4}, {1,5},
                            {2,2}, {2,3}, {2,4}, {2,5},
                            {3,3}, {3,4}, {3,5},
                            {4,4}, {4,5},
                            {5,5}};
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m; cin >> n >> m;
    if(m == 0){
        cout << 0 << '\n';
        return 0;
    }
    vector <int> edges_in_v(n, 0);
    vector <set<int>> adj_list(n);
    set <pair<int,int>> edges;
    for(int i=0; i<m; i++){
        int a, b; cin >> a >> b;
        a--; b--;
        edges.insert(mp(a,b));
        adj_list[a].insert(b);
        adj_list[b].insert(a);
        edges_in_v[a]++;
        edges_in_v[b]++;
    }
    int ans = 0;
    if(n == 7){
        for(int i=0; i<n; i++){
            // quitar el i, probar colocarle numeros del 1 al 6
            for(int j=0; j<6; j++){
                int add = 0;
                int k = j;
                if(k >= i) k++;
                for(int v : adj_list[i]){
                    if(adj_list[v].find(k) == adj_list[v].end()){
                        add++; 
                    }
                }
                ans = max(ans, m-edges_in_v[i]+add);
            } 
        }
    }
    else{
        ans = m;
    }
    cout << ans << '\n';
    return 0;
}
