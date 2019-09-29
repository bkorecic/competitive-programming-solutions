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
	vector <pair<ii, int>> tree;
	int n;
	
	pair <ii, int> merge(pair <ii, int> a, pair <ii, int> b){
		int join = min(a.f.f, b.f.s);
		return {{a.f.f + b.f.f - join, a.f.s + b.f.s - join}, a.s + b.s + join};
	}
	
	SegmentTree(string s){
		n = s.length();
		tree.resize(2*n);
		for(int i=0; i<n; i++){
			if(s[i] == '('){
				tree[i+n] = {{1, 0}, 0};
			}
			else{
				tree[i+n] = {{0, 1}, 0};
			}
		}
		for(int i = n-1; i>0; i--){
			tree[i] = merge(tree[i<<1], tree[i<<1|1]);
		}
	}
	
	int query(int i, int j){
		pair <ii, int> ansl = {{0,0}, 0}, ansr = {{0,0}, 0};
		for(i+=n, j+=n; i<j; i>>=1, j>>=1){
			if(i&1)ansl = merge(ansl, tree[i++]);
			if(j&1)ansr = merge(tree[--j], ansr);
		}
		pair <ii, int> ans = merge(ansl, ansr);
		return 2*ans.s;
	}
	
};

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	string s; cin >> s;
	int m; cin >> m;
	SegmentTree ST(s);
	for(int i=0; i<m; i++){
		int l, r; cin >> l >> r;
		l--; r--;
		cout << ST.query(l, r+1) << '\n';
	}
	return 0;
}
