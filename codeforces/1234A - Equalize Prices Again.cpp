#include <bits/stdc++.h>
#define f first
#define s second
 
using namespace std;
 
typedef long long ll;
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int q; cin >> q;
    while(q--){
        int n; cin >> n;
        ll sum = 0;
        for(int i=0; i<n; i++){
            ll aux; cin >> aux;
            sum += aux;
        }
        while(sum%n != 0){
            sum++;
        }
        cout << sum/n << '\n';
    }
    return 0;
}
