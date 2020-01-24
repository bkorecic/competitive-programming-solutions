#include <bits/stdc++.h>
#define f first
#define s second
 
using namespace std;
 
typedef long long ll;
 
vector <int> nums;
vector <int> ans;
bool done = false;
int n;
 
void solve(int put, int sz = 1){
    if(put < 0 || put > 3 || nums[put] <= 0) return;
    ans.push_back(put);
    if(sz == n){
        done = true;
        return;
    }
    nums[put]--;
    if(put > 0 && nums[put-1] > 0){
        solve(put-1, sz+1);
    }
    else{
        solve(put+1, sz+1);
    }
}
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    vector <int> in(4);
    cin >> in[0] >> in[1] >> in[2] >> in[3];
    n = in[0]+in[1]+in[2]+in[3];
    ans.resize(n);
    for(int i=0; i<=3; i++){
        ans.clear();
        nums = in;
        solve(i);
        if(done){
            cout << "YES\n";
            bool first = true;
            for(int j : ans){
                if(!first) cout << ' ';
                cout << j;
                first = false;
            } cout << '\n';
            return 0;
        }
    }
    if(!done) cout << "NO\n";
    return 0;
}
