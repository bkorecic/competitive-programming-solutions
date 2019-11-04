#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    int n, m; cin >> n >> m;
    int min_a = 100;
    int min_b = 100;
    int max_a = 0;
    for(int i=0; i<n; i++){
        int a; cin >> a;
        min_a = min(min_a, a);
        max_a = max(max_a, a);
    }
    for(int i=0; i<m; i++){
        int b; cin >> b;
        min_b = min(min_b, b);
    }
    int v = max(2*min_a, max_a);
    if(v < min_b){
        cout << v << '\n';
    }
    else{
        cout << -1 << '\n';
    }
}
