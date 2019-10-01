#include <bits/stdc++.h>
#define f first
#define s second
 
using namespace std;
 
typedef long long ll;
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, k; cin >> n >> k;
    queue <int> q;
    map <int, bool> used;
    int qsize = 0;
    for(int i=0; i<n; i++){
        int in; cin >> in;
        if(used[in]) continue;
        if(qsize+1 > k){
            used[q.front()] = false;
            q.pop();
            qsize--;
        }
        q.push(in);
        used[in] = true;
        qsize++;  
    }
    cout << qsize << '\n';
    stack <int> rq;
    while(!q.empty()){
        rq.push(q.front());
        q.pop();
    }
    bool flag = false;
    while(!rq.empty()){
        if(flag) cout << ' '; 
        cout << rq.top();
        rq.pop();
        flag = true;
    } cout << '\n'; 
    return 0;
}
