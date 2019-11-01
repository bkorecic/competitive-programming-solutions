#include <bits/stdc++.h>
#define f first
#define s second

using namespace std;

typedef long long ll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while(t--){
        int a, b; cin >> a >> b;
        if(__gcd(a,b) == 1){
            cout << "Finite\n";
        }
        else{
            cout << "Infinite\n";
        }
    }

    return 0;
}
