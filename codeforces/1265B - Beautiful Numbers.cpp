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
        vector <ll> nums(n);
        map <int, int> next_pos;
        for(int i=0; i<n; i++){
            cin >> nums[i];
            next_pos[nums[i]] = i;
        }
        int l = next_pos[1], r = l;
        int nw = 1;
        int biggest = 1;
        for(int m=1; m<=n; m++){
            next_pos.erase(nw);
            if(biggest == m){
                cout << 1;
            }
            else{
                cout << 0;
            }
 
            int next_ind = (*next_pos.begin()).s;
            if(next_ind > r){
                r++;
                nw = nums[r]; 
            }
            else if(next_ind < l){
                l--;
                nw = nums[l];
            }
            biggest = max(biggest, nw);
        } cout << '\n';
    }
}
