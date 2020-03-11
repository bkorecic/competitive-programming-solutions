#include <bits/stdc++.h>
#define f first
#define s second
 
using namespace std;
 
typedef long long ll;
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while(t--){
        int n; string s;
        cin >> n >> s;
        for(int i=n-1; i>=0; i--){
            if((s[i]-'0')%2 != 0) break;
            s[i] = 'x';
        }
        int sum = 0;
        for(int i=0; i<n; i++){
            if(s[i] != 'x'){
                sum += (s[i]-'0');
            }
        }
        if(sum%2 != 0){
            int last;
            for(int i=n-1; i>=0; i--){
                if(s[i] != 'x'){
                    last = i;
                    break;
                }
            }
            for(int i=last-1; i>=0; i--){
                if(s[i] != 'x' && (s[i]-'0')%2 != 0){
                    s[i] = 'x';
                    sum++;
                    break;
                }
            }
        }
        int remaining = 0;
        bool leadingzero = true;
        for(int i=0; i<n; i++){
            if(s[i] != 'x'){
                if(s[i] != '0') leadingzero = false;
                break;
            }
        }
        for(int i=0; i<n; i++){
            if(s[i] != 'x') remaining++;
        }
        if(remaining>0 && sum%2==0 && !leadingzero){
            for(int i=0; i<n; i++){
                if(s[i] != 'x') cout << s[i];
            } cout << '\n';
        }
        else cout << -1 << '\n';
    }
 
    return 0;
}
