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
        int sum = 2*(n-1) + 3;
        if(n==1){
            cout << -1 << '\n';
        }
        else{ 
            if(sum%3 != 0){
                for(int i=0; i<n-1; i++) cout << 2;
                cout << 3 << '\n';
            }
            else{
                for(int i=0; i<n-2; i++) cout << 2;
                cout << 33 << '\n';
            }
        }
    }
    return 0;
}