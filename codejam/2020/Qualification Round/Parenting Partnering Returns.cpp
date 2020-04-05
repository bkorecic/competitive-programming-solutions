#include <bits/stdc++.h>
#define f first
#define s second
#define mp make_pair

using namespace std;

typedef long long ll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    int testcase = 1;
    while(t--){
        int n; cin >> n;
        string ans(n,'0');
        vector<vector<bool>> assigned(24*60+1, vector<bool>(2,false)); // 0 is C
        // input
        vector<pair<pair<int,int>,int>> event(n);
        for(int i=0; i<n; i++){
            cin >> event[i].f.f >> event[i].f.s;
            event[i].s = i;
        }
        sort(event.begin(), event.end());
        for(int i=0; i<n; i++){
            int s = event[i].f.f, e = event[i].f.s;
            bool find_c = false;
            bool find_j = false;
            for(int t=s; t<e; t++){
                if(assigned[t][0]) find_c = true;
                if(assigned[t][1]) find_j = true;
            }
            if(find_c && find_j){
                ans = "IMPOSSIBLE";
                break;
            }
            else if(find_c){
                ans[event[i].s] = 'J';
                for(int t=s; t<e; t++){
                    assigned[t][1] = true;
                }
            } 
            else{
                ans[event[i].s] = 'C';
                for(int t=s; t<e; t++){
                    assigned[t][0] = true;
                }
            }
        }
        cout << "Case #" << testcase++ << ": " << ans << '\n';
    }

    return 0;
}
