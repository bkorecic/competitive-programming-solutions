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
        if(n==1){ 
            cout << s << '\n';
            continue;
        }
        set <char> ans;
        char cur = s[0];
        int adj = 1;
        for(int i=1; i<n; i++){
            //cout << i << ' ' << adj << ' ' << cur << endl;
            if(s[i] == cur){
                adj++;
            }
            if(s[i] != cur){
                if(adj%2 != 0){
                    ans.insert(cur);
                }
                adj = 1;
            }
            cur = s[i];
        }
        if(adj%2 != 0) ans.insert(s[n-1]);
        for(char c : ans){
            cout << c;
        } cout << '\n';
    }
    return 0;
}
