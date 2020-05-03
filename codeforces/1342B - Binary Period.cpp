#include <bits/stdc++.h>
#define f first
#define s second
#define pb push_back
#define mp make_pair
 
using namespace std;
 
typedef long long ll;
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while(t--){
        string s; cin >> s;
        int n = s.size();
        bool all_equal = true;
        for(int i=1; i<n; i++){
            if(s[i] != s[0]) all_equal = false;
        }
        if(all_equal){
            cout << s << '\n';
            continue;
        }
        string ans = "";
        for(int i=0; i<n-1; i++){
            if(s[i] != s[i+1]){
                ans += s[i];
            }
            else{
                ans += s[i];
                if(s[i] == '1') ans += "0";
                else ans += "1";
            }
        }
        ans += s[n-1];
        cout << ans << '\n';
    }
    
    return 0;
}