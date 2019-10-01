#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;

typedef pair<int, int> ii;

typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ii> vii;

#define mp make_pair
#define pb push_back
#define f first
#define s second

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	ll n, m, k; cin >> n >> m >> k;
	vector <ll> A(n);
	for(int i=0; i<n; i++)cin >> A[i];
	vector <pair<pair<ll,ll>, ll>> op(m);
	for(int i=0; i<m; i++){
		cin >> op[i].f.f >> op[i].f.s >> op[i].s;
		op[i].f.f--; op[i].f.s--;
	}
	vector <ll> times(m,0);
	vector <ll> dif(m+1,0);
	for(int i=0; i<k; i++){
		int xi, yi; cin >> xi >> yi;
		xi--; yi--;
		dif[xi]++; dif[yi+1]--;
	}
	times[0] = dif[0];
	for(int i=1; i<m; i++){
		times[i] = times[i-1] + dif[i];
	}
	dif.assign(n+1, 0);
	dif[0] = A[0];
	for(int i=1; i<n; i++){
		dif[i] = A[i] - A[i-1];
	}
	for(int i=0; i<m; i++){
		int l = op[i].f.f;
		int r = op[i].f.s;
		dif[l] += times[i]*op[i].s;
		dif[r+1] -= times[i]*op[i].s;
	}
	A[0] = dif[0];
	cout << A[0];
	for(int i=1; i<n; i++){
		A[i] = A[i-1] + dif[i];
		cout << ' ' << A[i];
	}
	cout << '\n';
	return 0;
}
