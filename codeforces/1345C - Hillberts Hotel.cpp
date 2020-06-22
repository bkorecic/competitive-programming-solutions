#include <bits/stdc++.h>
#define f first
#define s second
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;

ll mod(ll a, ll b){
    return (a%b+b)%b;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector <int> f(n,0);
        vector <ll> a(n);
        for(int i=0; i<n; i++){
            cin >> a[i];
        }
        int max_f = 0;
        for(int i=0; i<n; i++){
            int j = mod(i + a[i%n], n);
            f[j]++;
            max_f = max(max_f, f[j]);
        }
        /*
        for(int i=0; i<n; i++){
            cout << i << ' ' << f[i] << '\n';
        }
        */
        if(max_f > 1) cout << "NO\n";
        else cout << "YES\n";
    }

    return 0;
}
