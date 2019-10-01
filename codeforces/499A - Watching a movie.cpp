#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second
#define mp make_pair
#define pb push_back

typedef long long ll;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, x; cin >> n >> x;
	int actual = 1;
	vector <pair <int,int>> moments(n);
	for(int i=0; i<n; i++){
		cin >> moments[i].f >> moments[i].s;
	}
	int ans = 0;
	for(int i=0; i<n; i++){
		while(actual + x <= moments[i].f){
			actual+=x;
		}
		ans+=moments[i].s - moments[i].f + 1;
		ans+=moments[i].f - actual;
		//if(i>0 and actual == moments[i-1].f) ans--;
		actual = moments[i].s+1;
	}
	cout << ans << '\n';
	return 0;
}
