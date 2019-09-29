#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second
typedef long long ll;
typedef pair<int,int> ii;

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	int n; cin >> n;
	int k; cin >> k;
	cout << min(k-1, n-k) + 3*n << '\n';
	
	return 0;
}