#include <bits/stdc++.h>
#define f first
#define s second
#define pb push_back
#define mp make_pair
 
using namespace std;
 
typedef long long ll;
 
vector <int> convert = {119, 18, 93, 91, 58, 107, 111, 82, 127, 123};
vector<vector<int>> cost(128, vector<int>(10,-1));
 
void precalc(){
    for(int x=0; x<=127; x++){
        for(int y=0; y<=9; y++){
            int to_bin = convert[y];
            if((x & (x^to_bin)) == 0){
                cost[x][y] = (__builtin_popcount(x^to_bin));
            }
        }
    } 
}
 
int bin_to_dec(string &s){
    int add = 1;
    int ans = 0;
    for(int i=s.size()-1; i>=0; i--){
        if(s[i]=='1') ans += add;
        add *= 2;
    }
    return ans;
}
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    precalc();
    int n, k; cin >> n >> k;
    vector <int> nums(n);
    for(int i=0; i<n; i++){
        string s; cin >> s;
        nums[i] = bin_to_dec(s);
    }
 
    vector <vector<bool>> dp(n+1, vector<bool>(k+1,false));
    dp[n][0] = true;
    for(int y=0; y<=9; y++){
        int ki = cost[nums[n-1]][y];
        if(ki != -1){
            dp[n-1][ki] = true;
        }
    }
 
    for(int i=n-2; i>=0; i--){
        for(int kt=0; kt<=k; kt++){
            for(int y=0; y<=9; y++){
                int ki = cost[nums[i]][y];
                if(ki != -1 && kt-ki >= 0 && dp[i+1][kt-ki] == true){
                    dp[i][kt] = true;
                }
            }
            
        }
    }
    string ans = "";
    bool can = true;
    for(int i=0; i<n; i++){
        for(int y=9; y>=0; y--){
            int ki = cost[nums[i]][y];
            //cout << i << ' ' << nums[i] << ' ' << y << ' ' << ki << endl;
            if(ki != -1 && k-ki >=0 && dp[i+1][k-ki] == true){
                ans += to_string(y);
                k -= ki;
                break;
            }
            if(y==0) can = false;
        }
    }
    if(can) cout << ans << '\n';
    else cout << "-1\n";
    
    return 0;
}