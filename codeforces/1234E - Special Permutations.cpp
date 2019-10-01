#include <bits/stdc++.h>
#define f first
#define s second
 
using namespace std;
 
typedef long long ll;
 
vector <ll> diff_arr;
 
void query_sum(int i, int j, ll val){
    int n = diff_arr.size();
    if(i<0 || i > n-1 || j < 0 || j > n-1) return;
    diff_arr[i] += val;
    if(j < n-1) diff_arr[j+1] -= val; 
}
 
void print_arr(vector <ll> &diff_arr){
    int n = diff_arr.size();
    ll curr = diff_arr[0];
    cout << curr;
    for(int i=1; i<n; i++){
        curr = curr + diff_arr[i];
        cout << ' ' << curr;
    } cout << '\n';
}
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m; cin >> n >> m;
    diff_arr.assign(n,0);
    vector <ll> nums;
    int aux; cin >> aux;
    nums.push_back(aux);
    int last = nums[0];
    for(int i=1; i<m; i++){
        cin >> aux;
        if(last != aux){
            nums.push_back(aux);
            last = aux;
        }
    }
    m = nums.size();
    for(int i=0; i<m-1; i++){
        int a = max(nums[i], nums[i+1]);
        int b = min(nums[i], nums[i+1]);
        query_sum(0, a-2, a);
        query_sum(a-1, a-1, -1);
        query_sum(a, n-1, a+1);
 
        query_sum(0, b-2, -b);
        query_sum(b-1, b-1, -1);
        query_sum(b, a-2, -b-1);
        query_sum(a-1, a-1, b+1);
        query_sum(a, n-1, -b-1);
    }
    print_arr(diff_arr);
    return 0;
}

