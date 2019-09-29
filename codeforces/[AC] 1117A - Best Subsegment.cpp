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
	int n; cin >> n;
	vector <int> nums(n,0);
	int mayor = 0;
	for(int i=0; i<n; i++){
		cin>>nums[i];
		if(nums[i] > mayor) mayor = nums[i];
	}
	int ans = 0;
	int contar = 0;
	for(int i=0; i<n; i++){
		if(nums[i] != mayor) contar = 0;
		if(nums[i] == mayor) contar++;
		if(contar > ans) ans = contar;
	}
	cout << ans << '\n';
	return 0;
}