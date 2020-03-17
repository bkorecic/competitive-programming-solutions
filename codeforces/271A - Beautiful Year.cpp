#include <bits/stdc++.h>
#define pb push_back

using namespace std;
typedef long long ll;

bool all_distinct(int y){
    string s = to_string(y);
    int n = s.size();
    vector <bool> f(10, false);
    for(int i=0; i<n; i++){
        if(f[s[i]-'0'] == true){
            return false;
        }
        f[s[i]-'0'] = true;
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int y; cin >> y;
    y++;
    while(!all_distinct(y)){
        y++;
    }
    cout << y << '\n';
}
