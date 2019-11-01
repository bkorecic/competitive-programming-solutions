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
        int a, b, c; cin >> a >> b >> c;
        string s; cin >> s;
        int wins = 0;
        string ans = "";
        for(int i=0; i<n; i++) ans += "0";
        for(int i=0; i<n; i++){
            if(s[i] == 'R' && b >= 1){
                wins++;
                b--;
                ans[i] = 'P';
            }
            if(s[i] == 'P' && c >= 1){
                wins++;
                c--;
                ans[i] = 'S';
            }
            if(s[i] == 'S' && a >= 1){
                wins++;
                a--;
                ans[i] = 'R';
            }
        }
        int comp = (n%2 == 0) ? n/2 : n/2 + 1;
        if(wins >= comp){
            cout << "YES\n";
            for(int i=0; i<n; i++){
                if(ans[i] == '0'){
                    if(a >= 1){
                        ans[i] = 'R'; 
                        a--;
                    }
                    else if(b >= 1){
                        ans[i] = 'P'; 
                        b--;
                    }
                    else if(c >= 1){
                        ans[i] = 'S'; 
                        c--;
                    }
                }
            }
            cout << ans << '\n';
        }
        else{
            cout << "NO\n";
        }
    }

    return 0;
}
