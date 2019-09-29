#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		string s; cin >> s;
		int len = s.length();
		int left = 1000;
		int right = 1000;
		for(int i=0; i<len; i++){
			if(s[i] == '>'){
				left = i;
				break;
			}
		}
		for(int i=len-1; i>=0; i--){
			if(s[i] == '<'){
				right = len - i - 1;
				break;
			}
		}
		cout << min(len-1, min(left, right)) << '\n';
	}
	return 0;
}