#include <bits/stdc++.h>
#define f first
#define s second
 
using namespace std;
 
typedef long long ll;
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        string s, t; cin >> s >> t;
        int dif = 0;
        for(int i=0; i<n; i++){
            if(s[i] != t[i]) dif++;
        }
        if(dif != 2){
            cout << "No\n";
        }
        else{
            for(int i=0; i<n; i++){
                if(s[i] != t[i]){
                    for(int j=i+1; j<n; j++){
                        if(s[j] != t[j]){
                            if(s[i] == s[j] && t[i] == t[j]) cout << "Yes\n";
                            else cout << "No\n";
                            break;
                        }
                    }
                    break;
                }
            }
        }
    }
 
    return 0;
}
