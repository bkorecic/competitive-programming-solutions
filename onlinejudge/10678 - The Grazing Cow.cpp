#include <bits/stdc++.h>
using namespace std;
#define PI acos(-1)

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int T; cin >> T;
	for(int rep = 0; rep<T; rep++){
		int D, L; cin >> D >> L;
		double y = 0.5*D, x = 0.5*L;
		double ans = PI*sqrt(x*x - y*y) * x;
		cout << fixed << setprecision(3) << ans << '\n';
	}
	return 0;
}