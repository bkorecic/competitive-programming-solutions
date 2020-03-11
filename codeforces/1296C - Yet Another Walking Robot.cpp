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
        string s; cin >> s;
        map<pair<int,int>, int> visited;
        int x=0,y=0;
        int time = 0;
        visited[{0,0}] = time;
        time++;
        int ansi, ansj;
        int anstime=1e6;
        for(int i=0; i<n; i++){
            if(s[i] == 'R') x++;
            else if(s[i] == 'L') x--;
            else if(s[i] == 'U') y++;
            else if(s[i] == 'D') y--;
 
            if(visited.find({x,y}) != visited.end()){
                int lt = visited[{x,y}];
                if(time - lt < anstime){
                    anstime = time-lt;
                    ansi=lt;
                    ansj=time;
                }
            }
            visited[{x,y}] = time;
            time++;
        }
        if(anstime == 1e6){
            cout << "-1\n";
        }
        else{
            cout << ansi+1 << ' ' << ansj << '\n';
        }
    }
 
    return 0;
}
