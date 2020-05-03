#include <bits/stdc++.h>
#define f first
#define s second
#define pb push_back
 
using namespace std;
 
int main(){
    int n, m; cin >> n >> m;
    vector <int> op(m);
    vector <int> ans(m);
    bool can = true;
    for(int i=0; i<m; i++){
        cin >> op[i];
        ans[i] = i+1;
        if(i+op[i]-1 > n) can = false;
    }
    int last_cell = ans[m-1] + op[m-1] - 1;
    int unused = n - last_cell;
    //cout << last_cell << ' ' << unused << endl;
    if(unused < 0) can = false;
    // expand
    vector <int> sum(m, 0);
    int sum_acum = 0;
    for(int i=m-1; i>=1; i--){
        int max_possible = op[i-1]-1;
        //cout << max_possible << ' ';
        max_possible = min(max_possible, n-(i+1+op[i]-1));
        //cout << max_possible << endl;
        sum[i] += min(max_possible, unused);
        //cout << "Adding " << sum[i] << " to i" << endl;
        unused -= sum[i];
    }
    if(!can || unused > 0){
        cout << -1 << '\n';
        return 0;
    }
    int acum = 0;
    for(int i=0; i<m; i++){
        acum += sum[i];
        cout << ans[i] + acum << " \n"[i==m-1];
    }
    return 0;
}