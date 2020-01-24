#include <bits/stdc++.h>
#define f first
#define s second
#define pb push_back
#define mp make_pair
 
using namespace std;
 
typedef long long ll;
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    vector <vector<int>> tri(n-2, vector<int>(3));
    vector <vector<int>> tri_in(n);
    for(int i=0; i<n-2; i++){
        cin >> tri[i][0] >> tri[i][1] >> tri[i][2];
        tri[i][0]--; tri[i][1]--; tri[i][2]--;
        tri_in[tri[i][0]].pb(i);
        tri_in[tri[i][1]].pb(i);
        tri_in[tri[i][2]].pb(i);
    }
    vector <int> ans;
    for(int i=0; i<n; i++){
        if(tri_in[i].size() == 1){
            ans.pb(i);
            break;
        }
    }
    ans.pb(0); ans.pb(0);
    for(int u : tri[tri_in[ans[0]][0]]){
        if(tri_in[u].size() == 2){
            ans[1] = u;
        }
        if(tri_in[u].size() == 3){
            ans[2] = u;
        }
    }
    int cur = ans[2], last = ans[1];
    vector <bool> taken(n, false);
    taken[ans[0]] = true; taken[ans[1]] = true;
    taken[ans[2]] = true;
    for(int rep=0; rep<n-3; rep++){ 
        for(int i : tri_in[cur]){
            //cout << "cur = " << cur+1 << endl;
            int cnt = 0;
            int fnd;
            for(int u : tri[i]){
                //cout << "\tu = " << u+1 << endl;
                if(u == last || u == cur) cnt++;
                else fnd = u;
            }
            //cout << "\tfnd = " << fnd+1 << endl;
            if(cnt == 2 && !taken[fnd]){
                ans.pb(fnd);
                last = cur;
                cur = fnd;
                taken[fnd] = true;
                break;
            }
        }
    }         
    for(int i=0; i<n; i++){
        cout << ans[i]+1 << " \n"[i==n-1];
    } 
    return 0;
}
