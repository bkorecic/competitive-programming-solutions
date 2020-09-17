#include <bits/stdc++.h>
#define f first
#define s second
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
vector <vector <ii>> items;
int n, t;

int try_q(int qmin){
    int total_price = 0;
    for(int i=0; i<6; i++){
        int minp = 1e6;
        for(int j=0; (size_t)j<items[i].size(); j++){
            if(items[i][j].s >= qmin && items[i][j].f < minp)
                minp = items[i][j].f;
        }
        total_price += minp;
    }
    if(total_price <= t) return true;
    return false;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> t;
    items.assign(6, vector<ii>());
    int max_q = 0;
    for(int i=0; i<n; i++){
        int type, p, q;
        cin >> type >> p >> q;
        if(1 <= type and type <= 6){
            items[type-1].pb({p, q});
        }
    }
    for(int test_q = t; test_q >= 0; test_q--){
        if(try_q(test_q)){
            cout << test_q << '\n';
            return 0;
        }
    }
    cout << 0 << '\n';
    return 0;
}
