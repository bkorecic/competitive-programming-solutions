#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define f first
#define s second
 
using namespace std;
 
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
 
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
    ll n; cin >> n;
    ll ans;
    if(n==1) ans = 1;
    else if(n==2) ans = 2;
    else if(n==3) ans = 6;
    else if(n%2 != 0) ans = n*(n-1)*(n-2);
    else if(n%3 != 0) ans = n*(n-1)*(n-3);
    else ans = (n-1)*(n-2)*(n-3);
    cout << ans << '\n';
	return 0;
}
