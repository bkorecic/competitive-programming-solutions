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
	int n,m,k; cin >> n >> m >> k;
	vector <ll> nums(n,0);
	for(int i=0; i<n; i++)cin>>nums[i];
	sort(nums.begin(),nums.end(),greater<int>());
	ll ans = (m/(k+1))*(k*nums[0]+nums[1]);
	ans += (m%(k+1))*nums[0];
	cout << ans << '\n';
	return 0;
}