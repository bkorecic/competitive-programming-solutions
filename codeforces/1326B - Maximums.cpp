#include <bits/stdc++.h>
#define f first
#define s second
 
using namespace std;
 
typedef long long ll;
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    vector <int> a(n), x(n), b(n);
    for(int i=0; i<n; i++) cin >> b[i];
    x[0] = 0;
    a[0] = b[0];
    for(int i=1; i<n; i++){
        x[i] = max(x[i-1], a[i-1]);
        a[i] = b[i]+x[i];
    }
    for(int i=0; i<n; i++){
        cout << a[i] << " \n"[i==n-1];
    }
    return 0;
}