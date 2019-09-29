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
	int max_num = 1e6+1;
	ll MOD = 1e9+7;
	vector <vector <int>> divisores(max_num+1);
	for(int i=1; i<=max_num; i++){
		for(int j=i; j<=max_num; j+=i){
			divisores[j].pb(i);
		}
	}
	int n; cin >> n;
	vector <int> nums(n);
	for(int i=0; i<n; i++)cin>>nums[i];
	vector <ll> contar(max_num+1, 0);
	contar[0] = 1;
	for(int i=0; i<n; i++){
		for(int j = divisores[nums[i]].size()-1; j>=0; j--){
			int div_actual = divisores[nums[i]][j];
			contar[div_actual] = (contar[div_actual] + contar[div_actual-1])%MOD;
		}
	}
	ll ans = 0;
	for(int i=1; i<max_num; i++){
		ans = (ans + contar[i])%MOD;
	}
	cout << ans << '\n';
	return 0;
}