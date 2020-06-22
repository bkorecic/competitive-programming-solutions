#include <bits/stdc++.h>
#define f first
#define s second
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, s; cin >> n >> s;
    if(2*n <= s){
        cout << "YES\n";
        for(int i=0; i<n-1; i++){
            cout << "2 ";
        }
        cout << s-(2*(n-1)) << '\n' << 1 << '\n';
    }
    else{
        cout << "NO\n";
    }

    return 0;
}
