#include <bits/stdc++.h>
#define f first
#define s second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll n, m, a; cin >> n >> m >> a;
    ll x = (n%a == 0) ? n/a : n/a + 1;
    ll y = (m%a == 0) ? m/a : m/a + 1;
    cout << x*y << '\n';
    return 0;
}
