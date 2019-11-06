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
        int n; cin >> n;
        string s, t; cin >> s >> t;
        vector <pair<int,int>> ans;
        for(int i=0; i<n; i++){
            if(s[i] != t[i]){
                for(int j=i+1; j<n; j++){
                    if(t[i] == t[j]){
                        ans.pb(mp(i, j));
                        swap(s[i], t[j]);
                        break;
                    }
                    else if(t[i] == s[j]){
                        ans.pb(mp(j,j));
                        swap(s[j], t[j]);
                        ans.pb(mp(i,j));
                        swap(s[i], t[j]);
                        break;
                    }
                }
            }
        }
       if(s == t){ 
            cout << "Yes\n" << ans.size() << '\n';
            for(auto p : ans){
                cout << p.f+1 << ' ' << p.s+1 << '\n';
            }
       }
       else{
        cout << "No\n";
       }
    } 
    return 0;
}
