#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;

typedef pair<int, int> ii;

typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ii> vii;

#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define EPS 1-e6
#define INF 1e6
#define PI acos(-1.0)

#define mp make_pair
#define pb push_back
#define f first
#define s second

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int N, Q; cin >> N >> Q;
	vi num(N);
	F0R(i,N)cin>>num[i];
	num.pb(-100);
	for(int rep=0; rep<Q; rep++){
		int x; cin >> x;
		//binarysearch
		int l = 0, r = N, mid = (l+r)/2;
		while(l<r){
			mid = (l+r)/2;
			//cout << l << ' ' << mid << ' ' << r <<  endl;
			if(num[mid]>=x)r=mid;
			else l = mid+1;
		}
		if(N==1 && x == num[0])cout << "0\n";
		else if(num[l]==x)cout << l << '\n';
		else cout << "-1\n";
	}
	return 0;
}
