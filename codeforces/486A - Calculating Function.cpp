#include <bits/stdc++.h>
#define pb push_back

using namespace std;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll n; cin >> n;
    if(n%2 == 0){
        cout << n/2 << '\n';
    }
    else{
        cout << -(n+1)/2 << '\n';
    }
}
