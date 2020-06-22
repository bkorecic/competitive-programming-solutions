#include <bits/stdc++.h>
#define f first
#define s second
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;

void solve(){
    int n, x; cin >> n >> x;
    int odd = 0, even = 0;
    for(int i=0; i<n; i++){
        int aux; cin >> aux;
        if(aux%2==0) even++;
        else odd++;
    }
    for(int i=1; i<=x; i+=2){
        if(odd >= i && even >= (x-i)){
            cout << "Yes\n";
            return;
        }
    }
    cout << "No\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while(t--) solve();

    return 0;
}
