#include <bits/stdc++.h>
#define f first
#define s second
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;

void solve(){
    int n, m; cin >> n >> m;
    int total = n*m;
    if(total%2 == 0){
        cout << total/2 << '\n';
    }
    else{
        cout << (total+1)/2 << '\n';
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while(t--) solve();

    return 0;
}
