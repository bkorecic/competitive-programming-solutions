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
        ll n, k; cin >> n >> k;
        ll div;
        for(int i=2; i<=n; i++){
            if(n%i==0){
                div = i;
                break;
            }
        }
        if(n%2 == 0){
            cout << n + 2*k << '\n';
        }
        else{
            cout << n + div + 2*(k-1) << '\n';
        }
    }
    return 0;
}
