#include <bits/stdc++.h>
#define f first
#define s second
 
using namespace std;
 
typedef long long ll;
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    vector <int> nums(n*n);
    int rep;
    if(n*n%2 == 0){
        rep = n*n/2;
    }
    else{
        rep = n*(n-1)/2;
    }
    for(int i=0; i<rep; i++){
        nums[i] = i%n;
        nums[n*n - i - 1] = i%n;
    }
    if(n*n%2 != 0){
        for(int i = rep; i < rep + n; i++){
            nums[i] = i-rep;
        }
    }
    vector <vector <int>> ans(n);
    for(int i=0; i<n*n; i++){
        ans[nums[i]].push_back(i);
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(j) cout << ' ';
            cout << ans[i][j]+1;
        } cout << '\n';
    }
    return 0;
}
