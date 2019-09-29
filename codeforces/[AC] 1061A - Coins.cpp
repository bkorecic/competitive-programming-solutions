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

int solve(int N, int S){
	if(N>=S)return 1;
	return 1 + solve(N, S-N);
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	ll N, S; cin >> N >> S;
	cout << solve(N, S) << '\n';
	return 0;
}