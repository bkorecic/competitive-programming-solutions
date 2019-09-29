#include <bits/stdc++.h>
#define f first
#define s second

using namespace std;

typedef long long ll;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int T; cin >> T;
	while(T--){
		int h, w; cin >> h >> w;
		vector <vector <int>> grid(h, vector<int>(w));
		vector <vector <int>> dp(h, vector<int>(w,0));
		for(int i=0; i<h; i++){
			for(int j=0; j<w; j++){
				cin >> grid[i][j];
			}
		}
		dp[0] = grid[0];
		for(int i=1; i<h; i++){
			for(int j=0; j<w; j++){
				if(j==0){
					dp[i][j] = max(dp[i-1][j], dp[i-1][j+1]) + grid[i][j];;
				}
				else if(j==w-1){
					dp[i][j] = max(dp[i-1][j], dp[i-1][j-1]) + grid[i][j];;
				}
				else{
					dp[i][j] = max(max(dp[i-1][j], dp[i-1][j+1]), dp[i-1][j-1]) + grid[i][j];;
				}
			}
		}
		int ans = 0;
		for(int i=0; i<w; i++){
			if(dp[h-1][i] > ans)ans = dp[h-1][i];
		}
		cout << ans << '\n';/*
		cout << '\n' << '\n';
		for(int i=0; i<h; i++){
			for(int j=0; j<w; j++){
				cout << dp[i][j] << ' ';
			}cout << '\n';
		}*/
	}
	return 0;
}