#include <bits/stdc++.h>
#define f first
#define s second
 
using namespace std;
 
typedef long long ll;
 
struct SegmentTree{
    // O(n) build, O(nlogn) query&update
	vector <ll> tree;
	int N;
	SegmentTree(vector <ll> &A){
		N = A.size();
		tree.resize(4*N);
		build(0, 0, N-1, A);
	}
 
	ll merge(ll a, ll b){
		return a|b;
	}
 
	void build(int n, int l, int r, vector <ll> &A){
		if(l == r){ // caso hoja
			tree[n] = A[l];
			return;
		}
		int mid = (l+r)/2; // caso general
		build(2*n+1, l, mid, A);
		build(2*n+2, mid+1, r, A);
		tree[n] = merge(tree[2*n+1], tree[2*n+2]);
	}
 
	ll query(int i, int j){
		return(query(0, 0, N-1, i, j));
	}
 
	ll query(int n, int l, int r, int i, int j){
		if(i <= l && r <= j){ // contenido completamente
			return tree[n];
		}
		if(r < i || j < l){ // fuera del rango
			return 0;
		}
		int mid = (l+r)/2; // contenido parcialmente
		ll a = query(2*n+1, l, mid, i, j);
		ll b = query(2*n+2, mid+1, r, i, j);
		return merge(a, b);
	}
 
	void update(int i, ll v){
		update(0, 0, N-1, i, v);
	}
 
	void update(int n, int l, int r, int i, ll v){
		if(l == r && r == i){ // hoja
			tree[n] = v;
			return;
		}
		if(i < l || r < i) return; // fuera del rango
		int mid = (l+r)/2; // contenido parcialmente
		update(2*n+1, l, mid, i, v);
		update(2*n+2, mid+1, r, i, v);
		tree[n] = merge(tree[2*n+1], tree[2*n+2]);
	}
};
 
int f(int a, int b){
    return (a|b) - b;
}
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    vector <ll> nums(n);
    for(int i=0; i<n; i++) cin >> nums[i];
    SegmentTree ST(nums);
    ll ans = 0;
    ll ansindex = 0;
    for(int i=0; i<n; i++){
        ll left=0, right=0;
        if(i>0){
            left = ST.query(0, i-1);
        }
        if(i<n-1){
            right = ST.query(i+1, n-1);
        }
        ll r = f(nums[i], left|right);
        if(r > ans){
            ans = r;
            ansindex = i;
        }
    }
    cout << nums[ansindex];
    for(int i=0; i<n; i++){
        if(i == ansindex) continue;
        cout << ' ' << nums[i];
    } cout << '\n';
    return 0;
}

