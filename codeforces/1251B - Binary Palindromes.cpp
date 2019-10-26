#include <bits/stdc++.h>
#define f first
#define s second
 
using namespace std;
 
typedef long long ll;
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int q; cin >> q;
    while(q--){
        int n; cin >> n;
        int unos = 0, ceros = 0;
        vector <int> sz;
        for(int i=0; i<n; i++){
            string s; cin >> s;
            int tmp = s.length();
            sz.push_back(tmp);
            for(int j=0; j<tmp; j++){
                if(s[j] == '1')unos++;
                else ceros++;
            }
        }
        sort(sz.begin(), sz.end());
        int ans = 0;
        for(int i=0; i<n; i++){
            int sum = sz[i];  
            while(sum>1){
                //cout << i << ' ' << sum << ' ' << ceros << ' ' << unos << endl;
                if(ceros > unos){
                    sum -= 2;
                    ceros -= 2;
                }
                else{
                    sum -= 2;
                    unos -= 2;
                }
            }
            if(ceros>=0 && unos>=0) ans++;
            else break;
        }
        cout << ans << '\n';
    } 
    return 0;
}
