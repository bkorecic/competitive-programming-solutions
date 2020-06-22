#include <bits/stdc++.h>
#define f first
#define s second
#define mp make_pair
#define pb push_back

#define MAX 1000001

using namespace std;

typedef long long ll;

struct FenwickTree {
    vector<int> bit;  // binary indexed tree
    int n;

    FenwickTree(int n) {
        this->n = n;
        bit.assign(n, 0);
    }

    FenwickTree(vector<int> a) : FenwickTree(a.size()) {
        for (size_t i = 0; i < a.size(); i++)
            add(i, a[i]);
    }

    int sum(int r) {
        int ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret += bit[r];
        return ret;
    }

    int sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }

    void add(int idx, int delta) {
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] += delta;
    }
};

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, q; cin >> n >> q;
    vector <int> freq(n+1,0);
    for(int i=0; i<n; i++){
        int aux; cin >> aux;
        freq[aux]++;
    }
    FenwickTree ft(freq);
    /*
    for(int i=1; i<=n; i++){
        cout << i << ' ' << ft.sum(i,i) << ' ' << freq[i]<< endl;
    }
    */
    for(int i=0; i<q; i++){
        int k; cin >> k;
        if(k>=1){
            // insert k into multiset
            ft.add(k, 1);
        }
        else{
            k = -k;
            // find k-th order statistics
            // binary search
            int l=0, r=n, mid;
            while(l<r){
                mid = (l+r)/2;
                if(ft.sum(1,mid) >= k)
                    r = mid;
                else
                    l = mid+1;
            }
            ft.add(l, -1);
            //cout << l << endl; // removed number
        }
    }
    int ans = 0;
    for(int i=1; i<=n; i++){
        int query = ft.sum(i,i);
        if(query > 0){
            ans = i;
            break;
        }
    }
    cout << ans << endl;
    return 0;
}
