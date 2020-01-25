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
    int n; cin >> n;
    vector <pair<string, int>> q(n);
    map <string, int> score;
    for(int i=0; i<n; i++){
        cin >> q[i].f >> q[i].s; 
        if(score.find(q[i].f) == score.end()){
            score[q[i].f] = q[i].s;
        }
        else{
            score[q[i].f] += q[i].s;
        }
    }
    int m = -1e8;
    for(auto p : score){
        m = max(m, p.s);
    }
    map <string, int> score2;
    for(int i=0; i<n; i++){
        if(score2.find(q[i].f) == score2.end()){
            score2[q[i].f] = q[i].s;
        }
        else{
            score2[q[i].f] += q[i].s;
        }
        if(score2[q[i].f] >= m && score[q[i].f] == m){
            cout << q[i].f << '\n';
            break;
        }
    }
    return 0;
}
