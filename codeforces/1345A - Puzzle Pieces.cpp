#include <bits/stdc++.h>
#define f first
#define s second
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while(t--){
        int n, m; cin >> n >> m;
        if(n>m) swap(n,m);
        if(n>1 && m>2) cout << "NO\n";
        else cout << "YES\n";
    }
    return 0;
}
