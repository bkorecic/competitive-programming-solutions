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

int B, P, L, N;
vector <ll> modpow;

struct SegmentTree{
	vector <pair<ll, int>> tree;
	int n;
	pair<ll, int> merge(pair<ll, int> a, pair<ll,int> b){
		int asize = a.s, bsize = b.s;
		ll ans = ((a.f%P * modpow[bsize])%P + b.f%P)%P;
		return {ans, asize + bsize};
	}
	SegmentTree(int L){
		n = L;
		tree.assign(2*n, {0,1});
		for(int i = n-1; i>0; i--){
			tree[i] = merge(tree[i<<1], tree[i<<1 | 1]);
		}
	}
	void update(int i, ll value){
		i+=n;
		tree[i] = {value, 1};
		while(i>1){
			i/=2;
			tree[i] = merge(tree[i<<1], tree[i<<1|1]);
		} /*
		cout << endl;
		for(int i=1; i<2*n; i++){
			cout << i << "(" << tree[i].f << "," << tree[i].s << ") ";
		}
		cout << endl; */
	}
	ll query(int i, int j){
		/*
		pair<ll, int> ans = {0,0};
		for(i+=n, j+=n; i<j; i>>=1, j>>=1){
			if(i&1){
				ans = merge(ans, tree[i++]);
				
			}
			if(j&1){
				ans = merge(tree[--j], ans);
			}
		}
		*/
		pair<ll, int> ansl = {0,0};
		pair<ll, int> ansr = {0,0};

		for(i+=n, j+=n; i<j; i>>=1, j>>=1){
			if(i&1){
				ansl = merge(ansl, tree[i++]);
				
			}
			if(j&1){
				ansr = merge(tree[--j], ansr);
			}
		}
		pair<ll, int> ans = merge(ansl, ansr);
		return ans.f;
	}
};

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	while(cin >> B, B != 0){
		cin >> P >> L >> N;
		modpow.assign(L+1, 1);
		ll aux = B;
		for(int i=1; i<=L; i++){
			modpow[i] = aux;
			aux = (aux*B)%P;
		}
		SegmentTree ST(L);	
		for(int i=0; i<N; i++){
			char op; cin >> op;
			if(op == 'E'){
				int indice, value; cin >> indice >> value;
				indice--;
				ST.update(indice, value);
			}
			else{
				int l, r; cin >> l >> r;
				l--; r--;
				cout << ST.query(l, r+1) << '\n';
			}
		}
		cout << "-\n";
	}
	return 0;
}
