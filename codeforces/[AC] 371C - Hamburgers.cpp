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
	string bread; cin >> bread;
	ll nb, ns, nc, pb, ps, pc, r;
	cin >> nb >> ns >> nc >> pb >> ps >> pc;
	cin >> r;
	ll cant_b=0, cant_s=0, cant_c=0;
	for(int i=0;i<bread.length(); i++){
		if(bread[i]=='B')cant_b++;
		else if(bread[i]=='S')cant_s++;
		else cant_c++;
	}
	//binary search
	ll L=0, R=1e15, mid;
	while(L<R){
		mid = (L+R)/2;
		bool can = false;
		ll cb = max(0LL,mid*cant_b - nb);
		ll cs = max(0LL,mid*cant_s - ns);
		ll cc = max(0LL,mid*cant_c - nc);
		if(cb*pb+cs*ps+cc*pc<=r)can=true;
		if(!can)R=mid;
		else L=mid+1;
	}
	ll cb = max(0LL,mid*cant_b - nb);
	ll cs = max(0LL,mid*cant_s - ns);
	ll cc = max(0LL,mid*cant_c - nc);
	if(cb*pb+cs*ps+cc*pc<=r){
		cout << mid << '\n';
	}
	else{
		cout << mid-1 << '\n';
	}
}
