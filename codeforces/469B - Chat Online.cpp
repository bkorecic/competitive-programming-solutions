#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second
#define mp make_pair
#define pb push_back

typedef long long ll;
typedef pair <int,int> ii;
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int p, q, l, r;
	cin >> p >> q >> l >> r;
	vector <ii> x(p);
	vector <ii> y(q);
	for(int i=0; i<p; i++)cin >> x[i].f >> x[i].s;
	for(int i=0; i<q; i++)cin >> y[i].f >> y[i].s;
	int ans = 0;
	for(int test = l; test <= r; test++){
		bool can = false;
		for(int i=0; i<q; i++){
			int left = y[i].f, right = y[i].s;
			for(int j=0; j<p; j++){
				if((left + test >= x[j].f && left + test <= x[j].s)
				 || (right + test >= x[j].f && right + test <= x[j].s)
				 || (left + test <= x[j].f && right + test >= x[j].s)){
					can = true;
				}
			}
		}
		if(can)ans++;
	}
	cout << ans << '\n';
	return 0;
}