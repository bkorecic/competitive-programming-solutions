#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef vector <int> vi;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, m; cin >> n >> m;
	cout << min(n,m) + 1 << '\n';
	int x = 0, y = m;
	while(x<=n && y>=0){
		cout << x << ' ' << y << '\n';
		x++; y--;
	}
	return 0;
}