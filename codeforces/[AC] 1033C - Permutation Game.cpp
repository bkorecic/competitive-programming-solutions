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

vector <int> nums;
vector <char> ans;
int N;
char dp(int start){
	int num = nums[start];
	queue <int> q;
	for(int i=start+num; i<N; i+=num){
		if(nums[i] > num)q.push(i);
	}
	for(int i=start-num; i>=0; i-=num){
		if(nums[i] > num)q.push(i);
	}
	bool Bfound = false;
	while(!q.empty()){
		int next = q.front();
		q.pop();
		if(ans[next] == 'x'){
			if(dp(next) == 'B'){
				Bfound = true;
			}
		}
		else if(ans[next] == 'B'){
			Bfound = true;
		}
		
	}
	if(Bfound){
		ans[start] = 'A';
		return 'A';
	}
	ans[start] = 'B';
	return 'B';
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N;
	nums.assign(N,0);
	ans.assign(N, 'x');
	int start;
	for(int i=0; i<N; i++){
		cin>>nums[i];
		if(nums[i] == 1) start = i;
	}
	dp(start);
	for(int i=0; i<N; i++){
		cout << ans[i];
	}
	cout << '\n';
	return 0;
}
