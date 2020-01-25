#include <bits/stdc++.h>
#define f first
#define s second
 
using namespace std;
 
typedef long long ll;
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    string s; cin >> s;
    int l = 0, r = 0;
    for(char c : s){
        if(c == 'L') l--;
        else r++;
    }
    cout << r - l + 1 << '\n';
    return 0;
}
