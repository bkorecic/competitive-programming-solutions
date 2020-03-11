#include <bits/stdc++.h>
#define f first
#define s second
 
using namespace std;
 
typedef long long ll;
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while(t--){
        int n, d; cin >> n >> d;
        vector <int> a(n);
        for(int i=0; i<n; i++) cin >> a[i];
        int i=1;
        for(int i=1; i<n; i++){
            int add = min(a[i], d/i);
            d -= add*i;
            if(d < 0) break;
            a[i] -= add;
            a[0] += add;
            //cout << i << ' ' << add << endl;
        }
        cout << a[0] << '\n';
    }
 
    return 0;
}
