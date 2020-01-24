#include <bits/stdc++.h>
#define f first
#define s second
#define pb push_back
#define mp make_pair
 
using namespace std;
 
typedef long long ll;
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while(t--){
        int n, m; cin >> n >> m;
        vector <int> w(n);
        for(int i=0; i<n; i++) cin >> w[i];
        if(n <= 2 || m < n){
            cout << -1 << '\n';
            continue;
        }
        sort(w.begin(), w.end());
        ll ans = 0;
        vector <pair<int,int>> chains;
        for(int i=0; i<n; i++){
            chains.pb(mp(i+1, (i+1)%n+1));
            ans += w[i] + w[(i+1)%n];
            m--;
        }
        while(m--){
            ans += w[0]+w[1]; 
            chains.push_back(make_pair(1, 2));
        }
        cout << ans << '\n';
        for(auto p : chains){
            cout << p.f << ' ' << p.s << '\n';
        }
    } 
    return 0;
}
