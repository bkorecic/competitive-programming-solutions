#include <bits/stdc++.h>
#define f first
#define s second
 
using namespace std;
 
int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector <int> nums(n);
        for(int i=0; i<n; i++) cin >> nums[i];
        set <int> left, right;
        set <int> leftans, rightans;
        int k = 0;
        bool rep = false;
        for(int i=0; i<n-1; i++){
            int ins = nums[i];
            if(left.find(ins) != left.end()) rep = true;
            left.insert(ins);
            if(*left.begin() == 1 && *left.rbegin() == i+1 && rep == false){
                leftans.insert(i+1);
            }
        }
        rep = false;
        for(int i=n-1; i>=0; i--){
            int ins = nums[i];
            if(right.find(ins) != right.end()) rep = true;
            right.insert(ins);
            if(*right.begin() == 1 && *right.rbegin() == n-i && rep == false){
                rightans.insert(n-i);
            }
        }
        vector <pair<int,int>> ans;
        for(auto l1 : leftans){
            if(rightans.find(n-l1) != rightans.end()){
                ans.push_back(make_pair(l1,n-l1));
            }
        }
        cout << ans.size() << '\n';
        for(auto p : ans){
            cout << p.f << ' ' << p.s << '\n';
        }
    }
    
    return 0;
}