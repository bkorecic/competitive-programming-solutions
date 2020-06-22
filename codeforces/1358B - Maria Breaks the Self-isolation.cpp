#include <bits/stdc++.h>
#define f first
#define s second
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;

void solve(){
    int n; cin >> n;
    vector <int> a(n);
    for(int i=0; i<n; i++) cin >> a[i];
    sort(a.begin(), a.end());

    int cur = 0;
    bool go = true;
    while(cur < n && go){
        go = false;
        for(int i=cur; i<n; i++){
            if(a[i] <= i+1){
                cur = i+1;
                go = true;
                break;
            }
        }
    }

    cout << cur+1 << '\n';
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while(t--){
        solve();
    }
    

    return 0;
}
