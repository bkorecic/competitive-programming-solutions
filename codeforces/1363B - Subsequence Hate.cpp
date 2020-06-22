#include <bits/stdc++.h>
#define f first
#define s second
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;

void solve(){
    string s; cin >> s;
    int n = s.size();
    vector <int> zeros_left(n,0);
    vector <int> zeros_right(n,0);
    
    if(s[0] == '0') zeros_left[0] = 1;
    if(s[n-1] == '0') zeros_right[n-1] = 1;
    for(int i=1; i<n; i++){
        zeros_left[i] = zeros_left[i-1];
        if(s[i] == '0') zeros_left[i]++;
    }
    for(int i=n-2; i>=0; i--){
        zeros_right[i] = zeros_right[i+1];
        if(s[i] == '0') zeros_right[i]++;
    }

    int ans = zeros_right[0];
    for(int i=0; i<n-1; i++){
        int ones_left = i+1-zeros_left[i];
        ans = min(ans, ones_left + zeros_right[i+1]);
    }
    ans = min(ans, n-zeros_right[0]);
    for(int i=0; i<n-1; i++){
        int ones_right = n-(i+1)-zeros_right[i+1];
        ans = min(ans, zeros_left[i] + ones_right);
    }

    cout << ans << '\n';
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while(t--){
        solve();
    }

    return 0;
}
