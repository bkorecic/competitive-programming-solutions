#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	vector <int> w(n);
	vector <int> sum(n);
	for(int i=0; i<n; i++)cin >> w[i];
	sum[0] = w[0];
	for(int i=1; i<n; i++)sum[i] = sum[i-1] + w[i];
	int m; cin >> m;
	for(int i=0; i<m; i++){
		int q; cin >> q;
		int l=0, r=n, m;
		while(l<r){
			m = (l+r)/2;
			if(sum[m] >= q){
				r = m;
			}
			else{
				l = m + 1;
			}
		}
		cout << l+1 << '\n';
	}
	return 0;
}