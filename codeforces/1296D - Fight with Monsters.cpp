#include <bits/stdc++.h>
#define f first
#define s second
 
using namespace std;
 
typedef long long ll;
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    ll a, b, k;
    cin >> n >> a >> b >> k;
    vector <ll> h(n);
    for(int i=0; i<n; i++) cin >> h[i];
    for(int i=0; i<n; i++){
        ll c = h[i]/(a+b);
        if(c*(a+b) == h[i]){
            h[i] -= (c-1)*(a+b);
        }
        else{
            h[i] -= c*(a+b);
        }
    }
    sort(h.begin(), h.end());
    int ans = 0;
    for(int i=0; i<n; i++){
        if(a >= h[i]){
            ans++; 
        }
        else{
            ll req_k = h[i]/a + (h[i]%a != 0) - 1;
            //cout << h[i] << ' ' << req_k << endl;
            if(req_k <= k){
                k -= req_k;
                ans++;
            }
            else{
                break;
            }
        }
    } //cout << endl;
    cout << ans << '\n';
    return 0;
}
