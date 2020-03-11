#include <bits/stdc++.h>
#define f first
#define s second
 
using namespace std;
 
typedef long long ll;
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int odd=0, even=0;
        for(int i=0; i<n; i++){
            int aux; cin >> aux;
            if(aux%2==0) even++;
            else odd++;
        }
        if(n%2 == 0){
            if(odd > 0 && even > 0) cout << "YES\n";
            else cout << "NO\n";
        }
        else{
            if(odd > 0) cout << "YES\n";
            else cout << "NO\n";
        }
    }
 
    return 0;
}
