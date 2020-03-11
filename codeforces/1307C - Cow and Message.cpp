#include <bits/stdc++.h>
#define f first
#define s second
 
using namespace std;
 
typedef long long ll;
 
const int ALPH = 'z'-'a'+1;
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    string s; cin >> s;
    int n = s.size();
    vector <vector<ll>> oc(ALPH, vector<ll>(ALPH,0));
    vector <vector<ll>> cnt(n, vector<ll>(ALPH,0));
    for(int i=n-1; i>=0; i--){
        if(i<n-1){
            for(int j=0; j<ALPH; j++) cnt[i][j] = cnt[i+1][j];
        }
        cnt[i][s[i]-'a']++;
    }
    for(int i=0; i<n-1; i++){
        int c = s[i]-'a';
        for(int j=0; j<ALPH; j++){
            oc[c][j] += cnt[i+1][j]; 
        }
    }
    ll ans = 0;
    for(int i=0; i<ALPH; i++){
        for(int j=0; j<ALPH; j++){
            ans = max(ans, oc[i][j]);
        }
    }
    // check for length 1 hidden msg
    vector <ll> r(ALPH,0);
    for(int i=0; i<n; i++){
        r[s[i]-'a']++;
        ans = max(ans, r[s[i]-'a']);
    }
    cout << ans << '\n';
    return 0;
}
