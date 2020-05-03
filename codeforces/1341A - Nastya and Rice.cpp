#include <bits/stdc++.h>
#define f first
#define s second
#define pb push_back
#define mp make_pair
 
using namespace std;
 
typedef long long ll;
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while(t--){
        int n, a, b, c, d;
        cin >> n >> a >> b >> c >> d;
        int lower = n*(a-b);
        int higher = n*(a+b);
        bool can = true;
        if(lower > (c+d) || higher < (c-d)) can = false;
        if(can) cout << "Yes\n";
        else cout << "No\n";
    }
    
    return 0;
}