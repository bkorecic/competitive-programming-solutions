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
	int n, m, k; cin >> n >> m >> k;
	vector <int> dist(n-1,0);
	int actual; cin >> actual;
	int ini = actual;
	for(int i=0; i<n-1; i++){
		int next; cin >> next;
		dist[i] = next-actual;
		actual = next;
	}
	sort(dist.begin(),dist.end(), greater<int>());
	
	/*
	for(int i=0; i<n-1; i++){
		cout << dist[i] << endl;
	} */
	
	int ans = actual - ini  + 1;
	for(int i=0; i<k-1; i++){
		ans -= dist[i] - 1;
	}
	cout << ans << '\n';
	return 0;
}