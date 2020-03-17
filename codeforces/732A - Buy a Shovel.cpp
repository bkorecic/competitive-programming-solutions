#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int k, r;
    cin >> k >> r;
    for(int i=1; i<=10; i++){
        int p = k*i;
        if(p%10 == r || p%10 == 0){
            cout << i << '\n';
            return 0;
        }
    }
}
