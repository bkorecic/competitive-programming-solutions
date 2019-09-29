#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, k; string t; cin >> n >> k >> t;
	string ans = t;
	int tlen = t.length();
	int len = ans.length();
	int fr = 0;
	for(int i=0; i<k; i++){
		bool possible = false;
		int aux;
		for(int j=tlen-1; j>0; j++){
			string sub = t.substr(0,j);
			int found = ans.substr(fr).find(sub);
			if(found!=-1){
				possible = true;
				fr = len-j;
				break;
			}
		}
		if(!possible)fr = len;
		string concat = t.substr(len-fr);
		ans += concat;
		len += concat.length();
	}
	cout << ans << '\n';
	return 0;
}