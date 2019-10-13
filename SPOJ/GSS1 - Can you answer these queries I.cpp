#include <bits/stdc++.h>
#define f first
#define s second
#define mp make_pair

using namespace std;

typedef long long ll;

struct Node{
    ll max_sum, max_pre, max_suf, sum;
    Node(){
        max_sum = sum = max_pre = max_suf = -1e12;
    }
    Node(ll _max_sum, ll _max_pre, ll _max_suf, ll _sum){
        max_sum = _max_sum;
        max_pre = _max_pre;
        max_suf = _max_suf;
        sum = _sum; 
    }

    void print(){
        cout << max_sum << ' ' << max_pre << ' ' << max_suf << ' ' << sum << '\n';
    }
};

struct SegmentTree{
    vector <Node> tree;
    Node neutral;
    int N;

    SegmentTree(vector <ll> &A){
        N = A.size();
        tree.assign(4*N, Node());
        build(0, 0, N-1, A);
    }

    Node merge(Node &a, Node &b){
        ll max_sum = max(a.max_suf + b.max_pre, max(a.max_sum, b.max_sum));
        ll max_pre = max(a.sum + b.max_pre, a.max_pre);
        ll max_suf = max(b.sum + a.max_suf, b.max_suf);
        ll sum = a.sum + b.sum;
        return Node(max_sum, max_pre, max_suf, sum);
    }

    void build(int n, int l, int r, vector <ll> &A){
        if(l == r){
            tree[n] = Node(A[l], A[l], A[l], A[l]); 
            return;
        }
        int mid = (l+r)/2;
        build(2*n+1, l, mid, A);
        build(2*n+2, mid+1, r, A);
        tree[n] = merge(tree[2*n+1], tree[2*n+2]);
    }

    ll query(int i, int j){
        return query(0, 0, N-1, i, j).max_sum;
    }

    Node query(int n, int l, int r, int i, int j){
        if(r < i || j < l) return neutral;
        if(i <= l && r <= j) return tree[n];
        int mid = (l+r)/2;
        Node a = query(2*n+1, l, mid, i, j);
        Node b = query(2*n+2, mid+1, r, i, j);
        return merge(a, b); 
    }

    void print(){
        cout << "NEUTRAL: ";
        neutral.print();
        for(int i=0; i<4*N; i++){
            cout << i << ": ";
            tree[i].print();
        }
    }
};

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int N; cin >> N;
    vector <ll> nums(N);
    for(int i=0; i<N; i++){
        cin >> nums[i];
    }
    SegmentTree ST(nums);
    int M; cin >> M;
    for(int i=0; i<M; i++){
        int x, y; cin >> x >> y;
        x--; y--;
        cout << ST.query(x, y) << '\n';
    }

    return 0;
}
