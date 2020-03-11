#include <bits/stdc++.h>
#define f first
#define s second
 
using namespace std;
 
typedef long long ll;
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while(t--){
        string s; cin >> s;
        int first = -1, last = -1;
        for(int i=0; i<s.size(); i++){
            if(s[i] == '1'){
                last = i;
                if(first == -1) first = i;
            }
        }
        int ans = 0;
        if(first == -1){
            cout << 0 << '\n';
            continue;
        }
        for(int i=first; i<=last; i++){
            if(s[i] == '0') ans++;
        }
        cout << ans << '\n';
    }
    return 0;
}
