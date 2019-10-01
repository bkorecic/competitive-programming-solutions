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

struct SegmentTree{
	vector <int> tree;
	int n;
	SegmentTree(){
		n = 1e6 + 1;
		tree.assign(2*n, 0);
	}
	void update(int i, int value){
		i+=n;
		tree[i] = value;
		while(i>1){
			i/=2;
			tree[i] = tree[i<<1] + tree[i<<1 | 1];
		}
	}
	int query(int i, int j){
		int ans = 0;
		for(i+=n, j+=n; i<j; i>>=1, j>>=1){
			if(i&1) ans+=tree[i++];
			if(j&1) ans+=tree[--j];
		}
		return ans;
	}
};

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	vector <pair <ll, ll>> aux(n);
	vector <ll> nums(n);
	for(int i=0; i<n; i++){
		cin >> aux[i].f;
		aux[i].s = i;
	}
	sort(aux.begin(), aux.end());
	for(int i=0; i<n; i++){
		nums[aux[i].s] = i+1;
	}
	vector <ll> left(n);
	vector <ll> right(n);
	SegmentTree ST1;
	for(int i=0; i<n; i++){
		ST1.update(nums[i], 1);
		left[i] = ST1.query(nums[i]+1, n+1);
	}
	SegmentTree ST2;
	for(int i=n-1; i>=0; i--){
		ST2.update(nums[i], 1);
		right[i] = ST2.query(0, nums[i]);
	}
	//for(int i=0; i<n; i++){
	//	cout << "i: " << i << "\tleft[i]: " << left[i] << "\tright[i]: " << right[i] << endl;
	//}
	ll ans = 0;
	for(int i=0; i<n; i++){
		ans += left[i] * right[i];
	}
	cout << ans << '\n';
	return 0;
}
