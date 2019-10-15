// solves https://www.spoj.com/problems/PSEGTREE/
#include <bits/stdc++.h>
#define f first
#define s second

using namespace std;

typedef long long ll;

struct Node{
    Node *left, *right;
    int val;
    Node(int a=0, Node *b=NULL, Node *c=NULL){
        val = a;
        left = b;
        right = c;
    }
    void build(int l, int r){
        if(l == r) return;
        left = new Node();
        right = new Node();
        int mid = (l+r)/2;
        left -> build(l, mid);
        right -> build(mid+1, r);
    }

    Node *update(int l, int r, int i, ll v){
        if(i < l || r < i){
            return this;
        }
        if(l == r){
            Node *ret = new Node(val, left, right);
            ret -> val += v;
            return ret;
        }
        int mid = (l+r)/2;
        Node *ret = new Node(val);
        ret -> left = left -> update(l, mid, i, v);
        ret -> right = right -> update(mid+1, r, i, v);
        ret -> val = ret -> left -> val + ret -> right -> val;
        return ret;
    }

    ll query(int l, int r, int i, int j){
        if(r < i || j < l) return 0;
        if(i <= l && r <= j) return val;
        int mid = (l+r)/2;
        return left -> query(l, mid, i, j) 
               + right -> query(mid+1,r, i, j);
    }
};

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int N; cin >> N;
    vector <Node*> root(1);
    root[0] = new Node();
    root[0] -> build(0,N-1);
    for(int i=0; i<N; i++){
        int x; cin >> x;
        root[0] = root[0] -> update(0, N-1, i, x);
    }
    int Q; cin >> Q;
    int cur_root = 0;
    while(Q--){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        if(a == 1){
            root.push_back(new Node());
            root[cur_root+1] = root[b] -> update(0, N-1, c-1, d);
            cur_root++;
        }
        else{
            cout << root[b] -> query(0, N-1, c-1, d-1) << '\n';
        }
    }
    return 0;
}