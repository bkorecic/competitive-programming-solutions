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

struct SegmentTree{
    vector <int> tree;
    int n;
    SegmentTree(vector <int> &arr){
		n = arr.size();
		tree.resize(2*n);
		copy(arr.begin(),arr.end(),tree.begin()+n);
		for(int i=n-1; i>0; i--){
			tree[i] = tree[i<<1]*tree[i<<1 | 1];
		}
	}
	
	void update(int i, int value){
		for(tree[i+=n] = value; i>1; i>>= 1){
			tree[i>>1] = tree[i] * tree[i^1];
		}
	}
    
    int query(int i, int j){
		int ans = 1;
		for(i+=n, j+=n; i<j; i>>=1, j>>=1){
			if(i&1) ans *= tree[i++];
			if(j&1) ans *= tree[--j];
		}
		return ans;
	}
	
};

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int N, K;
	while(cin >> N >> K){
		vector <int> seq(N);
		for(int i=0; i<N; i++){
			int aux; cin >> aux;
			if(aux!=0)aux /= abs(aux);
			seq[i] = aux;
		}
		SegmentTree ST(seq);
		string ans = "";
		for(int i=0; i<K; i++){
			char command; cin >> command;
			if(command == 'C'){
				int index, value; cin >> index >> value;
				index--;
				if(value!=0)value /= abs(value);
				ST.update(index, value);
			}
			else{
				int l, r; cin >> l >> r;
				l--; r--;
				int prod = ST.query(l, r+1);
				if(prod>0){
					ans += "+";
				}
				else if(prod<0){
					ans+= "-";
				}
				else{
					ans+= "0";
				}
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
