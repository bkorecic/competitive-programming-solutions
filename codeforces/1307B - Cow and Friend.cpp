#include <bits/stdc++.h>
#define f first
#define s second
 
using namespace std;
 
typedef long long ll;
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while(t--){
        int n, x; cin >> n >> x;
        set <int> nums;
        int m = 0;
        for(int i=0; i<n; i++){
            int aux; cin >> aux;
            nums.insert(aux);
            m = max(m, aux);
        }
        if(nums.find(x) != nums.end()){
            cout << 1 << '\n';
        }
        else if(x<m){
            cout << 2 << '\n';
        }
        else if(x>m){ 
            if(x%m == 0) cout << x/m << '\n';
            else cout << x/m + 1 << '\n';
        } 
    }
    return 0;
}
