#include <bits/stdc++.h>
#define f first
#define s second
#define mp make_pair
#define pb push_back

typedef long long ll;

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    int m; cin >> m;
    vector <int> b(n);
    int b_max = 0;
    for(int i=0; i<n; i++){
        cin >> b[i];
        b_max = max(b_max, b[i]);
    }
    int max_k = b_max + m;
    for(int i=0; i<n; i++){
        int s = b_max - b[i];
        s = min(s, m);
        b[i] += s;
        m -= s;
    }
    int min_k;
    if(m == 0) min_k = b_max;
    else{
        min_k = b_max + m/n + (m%n != 0);
    }
    cout << min_k << ' ' << max_k << '\n';
    return 0;
}
