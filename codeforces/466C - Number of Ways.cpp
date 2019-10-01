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
	int n; cin >> n;
	vector <int> nums(n);
	ll sumTotal = 0;
	for(int i=0; i<n; i++){
		cin>>nums[i];
		sumTotal+=nums[i];
	}
	if(sumTotal%3!=0){
		cout << "0\n";
	}
	else{
		ll sum = 0;
		ll sumpossible = 0;
		vector <int> possible(n, 0);
		for(int i=n-1; i>=2; i--){
			sum+=nums[i];
			if(sum==sumTotal/3){
				sumpossible++;
			}
			possible[i] = sumpossible;
		}/*
		cout << "POSSIBLE: ";
		for(int i=0; i<n; i++){
			cout << possible[i] << ' ';
		}
		cout << endl; */
		sum=0;
		ll ans = 0;
		for(int i=0; i<n-2; i++){
			sum+=nums[i];
			if(sum==sumTotal/3){
				ans+=possible[i+2];
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
