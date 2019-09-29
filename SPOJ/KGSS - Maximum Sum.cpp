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
	vector <pair<int,int>> tree;
	int n;
	
	pair <int,int> merge(ii a, ii b){
		if(a.f < b.f) swap(a,b);
		return {a.f, max(a.s, b.f)};
	}
	
	SegmentTree(vector <int> &arr){
		n = arr.size();
		tree.resize(n<<1);
		for(int i=0; i<n; i++){
			tree[i+n] = {arr[i], -1};
		}
		for(int i=n-1; i>0; i--){
			tree[i] = merge(tree[i<<1], tree[i<<1 | 1]);
		}
		
		//for(int i=0; i<2*n; i++){
		//	cout << "i = " << i << "\t" <<  tree[i].f << ' ' << tree[i].s << endl;
		//}
	}
	
	void update(int i, int value){
		i+=n;
		tree[i] = {value, -1};
		while(i>1){
			i/=2;
			tree[i] = merge(tree[i<<1], tree[i<<1 | 1]);
		}
	}
	
	ii query(int i, int j){
		ii ans = {-1, -1};
		for(i+=n, j+=n; i<j; i>>=1, j>>=1){
			if(i&1){
				//cout << "i = " << i << endl;
				ans = merge(ans, tree[i]);
				i++;
			}
			if(j&1){
				//cout << "j = " << j << endl;
				j--;
				ans = merge(ans, tree[j]);
			}
		}
		return ans;	
	}
};


int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int N; cin >> N;
	vector <int> seq(N);
	for(int i=0; i<N; i++)cin>>seq[i];
	SegmentTree ST(seq);
	int Q; cin >> Q;
	for(int i=0; i<Q; i++){
		char command; cin >> command;
		if(command == 'Q'){
			int x, y; cin >> x >> y;
			x--; y--;
			ii ans = ST.query(x, y+1);
			cout << ans.f + ans.s << '\n';
		}
		else{
			int x, value; cin >> x >> value;
			x--;
			ST.update(x, value);
		}
	}
	return 0;
}
