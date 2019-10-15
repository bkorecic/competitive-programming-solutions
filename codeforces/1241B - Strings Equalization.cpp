#include <bits/stdc++.h>
#define f first
#define s second
 
using namespace std;
 
typedef long long ll;
typedef vector <int> vi;
typedef vector <ll> vll;
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int q; cin >> q;
    while(q--){
        string s, t; cin >> s >> t;
        bool can = false;
        for(int i=0; i<s.length(); i++){
            for(int j=0; j<t.length(); j++){
                if(t[j] == s[i]){
                    can = true;
                    break;
                }
            }
            if(can)break;
        }
        if(can) cout << "YES\n";
        else cout << "NO\n";
    } 
    return 0;
}
