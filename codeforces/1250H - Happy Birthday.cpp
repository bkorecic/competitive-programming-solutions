#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while(t--){
        vector <int> dig(10);
        for(int i=0; i<10; i++) cin >> dig[i];
        int min_num = 1e6;
        int min_ind = 0;
        for(int i=1; i<10; i++){
            if(dig[i] < min_num){
                min_num = dig[i];
                min_ind = i;
            }
        }
        if(dig[0] < min_num){
            cout << 1;
            for(int i=0; i<dig[0]+1; i++) cout << 0;
            cout << '\n';
        }
        else{
            for(int i=0; i<min_num+1; i++){
                cout << min_ind;
            } cout << '\n';
        }
    }
    return 0;
}
