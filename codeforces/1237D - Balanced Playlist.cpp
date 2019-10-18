#include<bits/stdc++.h>
#define f first
#define s second
 
using namespace std;
 
typedef long long ll;
 
struct SegmentTree{
	vector <ll> tree;
	int N;
    ll neutro;
    bool minst;
	SegmentTree(vector <ll> &A, bool _minst = 0){
		N = A.size();
		tree.resize(4*N);
        minst = _minst;
        if(minst){
            neutro = 1e12;
        }
        else{
            neutro = -1;
        }
		build(0, 0, N-1, A);
	}
 
	ll merge(ll a, ll b){
        if(minst) return min(a,b);
        else return max(a,b);
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
			return neutro;
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
 
ll circle_query(int i, int j, SegmentTree &ST){
    if(j < i){
        if(ST.minst){
            return min(ST.query(i, ST.N - 1), ST.query(0, j));
        }
        else{
            return max(ST.query(i, ST.N - 1), ST.query(0, j));
        }
    }
    else{
        return ST.query(i, j); 
    }
}
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    vector <ll> nums(n);
    int max_ind;
    ll max_num = -1;
    for(int i=0; i<n; i++){
        cin >> nums[i];
        if(nums[i] > max_num){
            max_num = nums[i];
            max_ind = i;
        }
    }
    int j = (max_ind+1)%n;
    int dp_max = 1;
    while(2*nums[j] >= max_num){
        dp_max++;
        j = (j+1)%n;
        if(dp_max > n){
            for(int i=0; i<n; i++){
                if(i) cout << ' ';
                cout << -1;
            } cout << '\n';
            return 0;
        }
    }
    vector <int> dp(n);
    dp[max_ind] = dp_max;
    SegmentTree min_st(nums, 1);
    SegmentTree max_st(nums, 0);
    for(int i = (max_ind + n-1)%n; i != max_ind; i = (i+n-1)%n){
        // buscar primer numero mayor
        int L = 1, R = n-1, mid;
        while(L < R){
            mid = (L+R)/2;
            ll max_range = circle_query((i+1)%n, (i+mid)%n, max_st);
            if(max_range >= nums[i]) R = mid;
            else L = mid+1;
        }
        int max_diff = L; // siempre se encuentra
        // buscar primer numero x tal que 2*x < nums[i]
        L = 1; R = n-1;
        while(L < R){
            mid = (L+R)/2;
            ll min_range = circle_query((i+1)%n, (i+mid)%n, min_st);
            if(2*min_range < nums[i]) R = mid;
            else L = mid+1;
        }
        if(2*circle_query((i+1)%n, (i+L)%n, min_st) >= nums[i]) L = 1e6;
        int min_diff = L;
        // cout << "i, max_diff, min_diff: " << i << ' ' << max_diff << ' ' << min_diff << '\n';
        if(max_diff < min_diff){
            dp[i] = dp[(i+max_diff)%n] + max_diff;
        }
        else{
            dp[i] = min_diff;
        }
    }
    for(int i=0; i<n; i++){
        if(i) cout << ' ';
        cout << dp[i];
    } cout << '\n';
    return 0;
}
