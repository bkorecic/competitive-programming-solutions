#include <bits/stdc++.h>
#define f first
#define s second

using namespace std;
typedef long long ll;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	vector <ll> x(3);
	cin >> x[0] >> x[1] >> x[2];
	sort(x.begin(), x.end());
	if((x[0] + x[1])*2 <= x[2]){
		cout << x[0] + x[1] << '\n';
	}
	else{
		cout << (x[0] + x[1] + x[2])/3 << '\n';
	}
	return 0;
} 1 1 2