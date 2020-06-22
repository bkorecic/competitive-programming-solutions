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
        ll n; cin >> n;
        int ans = 0;
        while(n > 1){
            ll l = 1, r = 100000, mid;
            ll calc = 0;
            while(l < r){
                mid = (l+r)/2;
                calc = 3*mid*mid + mid;
                if(calc > 2*n){
                    r = mid;
                }
                else{
                    l = mid+1;
                }
            }
            l--;
            calc = (3*l*l + l)/2;
            //cout << "n = " << n << "\tl = " << mid << "\tcalc = " << calc << endl;
            ans++;
            n -= calc;
        }
        cout << ans << '\n';
    }

    return 0;
}
