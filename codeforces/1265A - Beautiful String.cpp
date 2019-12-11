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
        int n = s.length();
        for(int i=0; i<n; i++){
            if(s[i] == '?'){
                for(char x = 'a'; x <= 'c'; x++){
                    if((i==0 || (i>0 && s[i-1] != x)) && (i==n-1 || (i<n-1 && s[i+1] != x))){
                        s[i] = x;
                        break;
                    }
                }
            }
        }
        bool can = true;
        for(int i=1; i<n; i++){
            if(s[i] == s[i-1]) can = false;
        }
        if(can) cout << s << '\n';
        else cout << -1 << '\n';
    }
 
    return 0;
}
