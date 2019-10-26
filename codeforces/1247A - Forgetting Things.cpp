#include <bits/stdc++.h>
#define f first
#define s second
 
using namespace std;
 
typedef long long ll;
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll a, b;
    cin >> a >> b;
    if(b == 1 && a == 9){
        cout << 99 << ' ' << 100 << '\n';
    }
    else if(b > a+1 || a > b){
        cout << -1 << '\n';
    }
    else{
        if(a == b){
            cout << a << 0 << ' ' << b << 1 << '\n';
        }
        else if(a+1 == b){
            cout << a << 9 << ' ' << b << 0 << '\n';
        }
    } 
    return 0;
}
