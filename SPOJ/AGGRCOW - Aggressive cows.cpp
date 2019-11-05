#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;

typedef long long ll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T; cin >> T;
    while(T--){
        int N, C;
        cin >> N >> C;
        vector <ll> stalls(N);
        for(int i=0; i<N; i++){
            cin >> stalls[i];
        }
        sort(stalls.begin(), stalls.end());
        ll L = 1, R = 1e9, mid;
        while(L < R){
            mid = (L+R)/2;
            //cout << "mid=" <<  mid << '\n';
            ll dist = mid;
            ll lastPlaced = stalls[0];
            ll countPlaced = 1;
            for(int i=1; i<N; i++){
                if(stalls[i] - lastPlaced >= dist){
                    //cout << "\tstalls[i]= " << stalls[i] << '\n';
                    //cout << "\tlastPlaced=" << lastPlaced << '\n';
                    //cout << "\tdist=" << dist << '\n';
                    countPlaced++;
                    lastPlaced = stalls[i];
                }
            }
            if(countPlaced < C){
                R = mid;
            }
            else{
                L = mid + 1;
            }
        }
        cout << L-1 << '\n';
    }
    return 0;
}
