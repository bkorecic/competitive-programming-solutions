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

vector <int> nums;
vector <int> freq;
vector <pair<int,int>> bounds;

struct SegmentTree{
	vector <int> tree;
	int n;
	SegmentTree(vector <int> &arr){
		n = arr.size();
		tree.resize(2*n);
		copy(arr.begin(), arr.end(), tree.begin() + n);
		for(int i=n-1; i>0; i--){
			tree[i] = max(tree[i<<1], tree[i<<1|1]);
		}
	}
	int query(int i, int j){
		int ans = -1;
		for(i+=n, j+=n; i<j; i>>=1, j>>=1){
			if(i&1)ans = max(ans, tree[i++]);
			if(j&1)ans = max(ans, tree[--j]);
		}
		return ans;
	}
	
};

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, q;
	while(cin >> n, n!=0){
		cin >> q;
		nums.resize(n);
		freq.resize(n);
		bounds.resize(n);
		for(int i=0; i<n; i++)cin>>nums[i];
		int actual = nums[0], l = 0, cuenta = 0;
		for(int i=0; i<=n; i++){
			if(nums[i] != actual or i == n){
				for(int j = l; j<i; j++){
					freq[j] = cuenta;
					bounds[j].s = i-1;
				}
				if(i!=n){
					actual = nums[i];
					cuenta = 0;
					l = i;
				}
			}
			if(i!=n){
				bounds[i].f = l;
				cuenta++;
			}
		}
		SegmentTree ST(freq);
		for(int i=0; i<q; i++){
			int l, r; cin >> l >> r;
			l--; r--;
			int fleft = 0, fright = 0, fmid = 0;
			if(nums[l] == nums[r]){
				cout << r-l+1 << '\n';
			}
			else{
				fleft = freq[l] - (l - bounds[l].f);
				fright = freq[r] - (bounds[r].s - r);
				if(bounds[l].s + 1 < bounds[r].f){
					fmid = ST.query(bounds[l].s + 1 , bounds[r].f);
				}
				cout << max(max(fleft, fright), fmid) << '\n';
			}
		}
	}
	return 0;
}
