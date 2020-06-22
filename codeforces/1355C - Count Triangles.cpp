#include <bits/stdc++.h>
#define f first
#define s second
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll A, B, C, D; cin >> A >> B >> C >> D;
    ll ans = 0;
    for(ll x = A; x <= B; x++){
        ll ymin = max(B,C+1-x);
        //ll ymax = C;
        ll ymax = max(B,min(C,D+1-x));

        //cout << "x = " << x << '\n';

        //cout << '\t' <<  ymin << ' ' << ymax << '\n';

        ll L, R;
        if(x+ymin > D){
            L = (D-C)+1;
        }
        else{
            L = x+ymin-C;
        }
        if(x+ymax > D){
            R = (D-C)+1;
        }
        else{
            R = x+ymax-C;
        }

        //cout << '\t' <<  L << ' ' << R << '\n';

        ans += (R-L)*(R-L+1)/2 + (R-L+1)*L;
        ans += (C-ymax)*R;
    }
    cout << ans << '\n';
    return 0;
}
