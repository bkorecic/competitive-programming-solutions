#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second
typedef long long ll;
typedef pair<int,int> ii;

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	int n; cin >> n;
	vector <ii> pages(n);
	for(int i=0; i<n; i++){
		cin >> pages[i].f >> pages[i].s;
	}
	int k; cin >> k;
	int ans = n;
	for(int i=0; i<n; i++){
		int l = pages[i].f, r = pages[i].s;
		if(r < k)ans--;
	}
	cout << ans << '\n';
	return 0;
}