#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;

typedef pair<int, int> ii;

typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ii> vii;

#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)

#define mp make_pair
#define pb push_back
#define f first
#define s second

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int N; cin >> N;
	vector <int> prices(N);
	for(int i=0; i<N; i++)cin>>prices[i];
	sort(prices.begin(),prices.end());
	int Q; cin >> Q;
	for(int i=0; i<Q; i++){
		int x; cin >> x;
		//binary search x
		int L = 0, R = prices.size(), mid;
		while(L<R){
			mid = (L+R)/2;
			//cout << L << ' '  << mid << ' ' << R << endl;
			if(prices[mid] > x)R=mid;
			else L=mid+1;
		}
		if(prices[L] >= x || L == prices.size()){
			cout << L << '\n';
		}
		else cout << 0 << '\n';
		
	}
	return 0;
}