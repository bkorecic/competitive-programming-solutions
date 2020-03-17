#include <bits/stdc++.h>
#define pb push_back

using namespace std;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    string s; cin >> s;
    int ans = 0;
    for(int i=0; i<n-1; i++){
        while(s[i+1] == s[i] && i < n-1){
            ans++;
            i++;
        }
    }
    cout << ans << '\n';
}
