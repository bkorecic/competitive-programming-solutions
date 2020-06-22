#include <bits/stdc++.h>
#define f first
#define s second
#define mp make_pair
#define pb push_back
 
using namespace std;
 
typedef long long ll;
 
bool is_prime(int m){
    for(int i=2; i*i<=m; i++){
        if(m%i==0) return false;
    }
    return true;
}
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    for(int m=1; m<=1000; m++){
        if(!is_prime(n*m+1)){
            cout << m << '\n';
            break;
        }  
    }
 
    return 0;
}
