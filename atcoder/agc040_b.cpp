#include <bits/stdc++.h>
#define f first
#define s second

using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;

struct SegmentTree{
    vector <ll> tree;
    bool minst;
    int N;
    ll neutro;
    SegmentTree(vector <ll> &A, bool _minst){
        minst = _minst;
        N = A.size();
        tree.resize(4*N);
        if(minst) neutro = 1e9;
        else neutro = 0;
        build(0, 0, N-1, A);
    }
    ll merge(ll a, ll b){
        if(minst) return min(a,b);
        else return max(a,b);
    }
    void build(int n, int l, int r, vector<ll> &A){
        if(l == r){
            tree[n] = A[l];
            return;
        }
        int mid = (l+r)/2;
        build(2*n+1, l, mid, A);
        build(2*n+2, mid+1, r, A);
        tree[n] = merge(tree[2*n+1], tree[2*n+2]);
    }
    ll query(int i, int j){
        return query(0, 0, N-1, i, j);
    }
    ll query(int n, int l, int r, int i, int j){
        if(r < i || j < l) return neutro;
        if(i <= l && r <= j) return tree[n];
        int mid = (l+r)/2;
        ll a = query(2*n+1, l, mid, i, j);
        ll b = query(2*n+2, mid+1, r, i, j);
        return merge(a,b);
    }
};

ll calc(ll L, ll R){
    return max(0LL, R-L+1);
}

bool comp(pll a, pll b){
    return (a.s-a.f+1) < (b.s-b.f+1);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    vector <pll> nums(n);
    for(int i=0; i<n; i++){
        cin >> nums[i].f >> nums[i].s;
    }
    sort(nums.begin(), nums.end());
    vector <ll> L(n);
    vector <ll> R(n);
    for(int i=0; i<n; i++){
        L[i] = nums[i].f;
        R[i] = nums[i].s;
    }
    SegmentTree max_L(L, 0);
    SegmentTree min_R(R, 1);
    ll L1, R1, L2, R2;
    ll ans = 0;
    for(int i=0; i<n-1; i++){
        L1 = max_L.query(0, i);
        R1 = min_R.query(0, i);
        L2 = max_L.query(i+1,n-1);
        R2 = min_R.query(i+1,n-1);
        ans = max(ans, calc(L1,R1)+calc(L2,R2));
    }

    sort(nums.begin(), nums.end(), comp);
    for(int i=0; i<n; i++){
        L[i] = nums[i].f;
        R[i] = nums[i].s;
    }
    SegmentTree max2_L(L, 0);
    SegmentTree min2_R(R, 1);
    for(int i=0; i<n-1; i++){
        L1 = max2_L.query(0, i);
        R1 = min2_R.query(0, i);
        L2 = max2_L.query(i+1, n-1);
        R2 = min2_R.query(i+1, n-1);
        ans = max(ans, calc(L1,R1)+calc(L2,R2));
    }
    cout << ans << '\n';
    return 0;
}
