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
	int n; cin >> n;
	vector <pair <int,int> > laptops(n);
	for(int i=0; i<n; i++){
		cin>>laptops[i].f;
		cin>>laptops[i].s;
	}
	sort(laptops.begin(),laptops.end());
	int last = laptops[0].s;
	bool alex = true;
	for(int i=1; i<n;i++){
		if(laptops[i].s < last){
			alex = false;
		}
		last = laptops[i].s;
	}
	if(!alex) cout << "Happy Alex\n";
	else cout << "Poor Alex\n";
	return 0;
}
