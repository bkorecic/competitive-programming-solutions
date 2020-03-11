#include <bits/stdc++.h>
#define f first
#define s second
#define pb push_back
#define mp make_pair
 
using namespace std;
 
typedef long long ll;
typedef pair<int,int> ii;
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t; 
    while(t--){
        int n; cin >> n;
        string s = "";
        while(n > 1){
            s = "1" + s;
            n-=2;
        }
        if(n == 1){
            s[0] = '7';
        }
        cout << s << '\n';
    }
    return 0;
}
