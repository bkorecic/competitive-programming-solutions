#include <bits/stdc++.h>
#define f first
#define s second
#define mp make_pair

using namespace std;

typedef long long ll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    int testcase = 1;
    while(t--){
        string s; cin >> s;
        s += "0";
        int n = s.size();
        vector <int> nums(n);
        for(int i=0; i<n; i++){
            nums[i] = s[i]-'0';
        }
        string ans = "";
        int cur_depth = 0;
        for(int i=0; i<n; i++){
            int dir;
            char par;
            if(nums[i] > cur_depth){
                dir = 1;
                par = '(';
            }
            else if(nums[i] < cur_depth){
                dir = -1;
                par = ')';
            }
            while(cur_depth != nums[i]){
                cur_depth += dir;
                ans += par;
            }
            if(i != n-1) ans += s[i];
        }
        cout << "Case #" << testcase++ << ": " << ans << '\n';
    }
    return 0;
}
