#include <bits/stdc++.h>
#define f first
#define s second
 
using namespace std;
 
typedef long long ll;
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    string s; cin >> s;
    string t = s;
    sort(t.begin(), t.end());
    vector <int> target(n, -1);
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(s[j] == t[i] && target[j] == -1){
                target[j] = i;
                break;
            }
        }
    }
    vector <int> color(n, -1);
    bool can = true;
    for(int i=n-1; i>=0; i--){
        if(color[i] == -1) color[i] = 1;
        for(int j=0; j<n; j++){
            if(target[j] > target[i] && j < i){
                if(color[j] == -1) color[j] = color[i]^1;
                else if(color[j] == color[i]) can = false;
            }
        }
    }
    if(can){
        cout << "YES\n";
        for(int i=0; i<n; i++) cout << color[i];
        cout << endl;
    }
    else{
        cout << "NO\n";
    }
    return 0;
}

