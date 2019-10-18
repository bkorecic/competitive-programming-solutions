#include <bits/stdc++.h>
#define f first
#define s second
 
using namespace std;
 
typedef long long ll;
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    vector <int> enter(n);
    vector <int> exit(n);
    for(int i=0; i<n; i++) cin >> enter[i];
    map <int, int> exit_pos;
    for(int i=0; i<n; i++){
        cin >> exit[i];
        exit_pos[exit[i]] = i;
    }
    int max_exit = exit_pos[enter[0]];
    int ans = 0;
    for(int i=1; i<n; i++){
        if(exit_pos[enter[i]] < max_exit) ans++;
        max_exit = max(max_exit, exit_pos[enter[i]]);
    }
    cout << ans << '\n';
    return 0;
}
