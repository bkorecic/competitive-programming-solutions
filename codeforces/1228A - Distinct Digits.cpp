#include <bits/stdc++.h>
#define f first
#define s second

using namespace std;

typedef long long ll;

/*
bool digits_repeat(int x){
    int len = log10(x) + 1;
    vector <bool> cnt(10, false);
    while(len--){
        int d = x%10;
        if(cnt[d] = t
    }
}
*/
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int l, r; cin >> l >> r;
    int ans = -1;
    for(int i=l; i<=r; i++){
        vector <bool> cnt(10,false);
        bool can = true;
        int aux = i;
        while(aux>0){
            int d = aux%10;
            //cout << "aux = " << i << "\td = " << d << ' ' << cnt[d] << endl;
            if(cnt[d] == true){
                can = false;
                //cout << "xd" << endl;
                break;
            }
            cnt[d] = true;
            aux /= 10;
        }
        if(can){
            ans = i;
            break;
        }
    }
    cout << ans << '\n';


    return 0;
}
