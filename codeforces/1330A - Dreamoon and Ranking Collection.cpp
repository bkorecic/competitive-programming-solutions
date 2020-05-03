#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    int t; cin >> t;
    while(t--){
        int n, x; cin >> n >> x;
        vector <int> freq(300,0);
        for(int i=0; i<n; i++){
            int tmp; cin >> tmp;
            freq[tmp]++;
        }
        int cnt_zero = 0;
        for(int i=1; i<300; i++){
            if(freq[i] == 0) cnt_zero++;
            if(cnt_zero == x+1){
                cout << i-1 << '\n';
                break;
            }
        }
    }
    
    return 0;
}