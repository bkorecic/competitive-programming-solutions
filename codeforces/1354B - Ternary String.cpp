#include <bits/stdc++.h>
#define f first
#define s second
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;

void solve(){
    string s; cin >> s;
    int n = s.size();
    int l=1, r=n, mid;
    bool i1=false,i2=false,i3=false;
    for(int i=0; i<n; i++){
        if(s[i] == '1') i1 = true;
        if(s[i] == '2') i2 = true;
        if(s[i] == '3') i3 = true;
    }
    if(!i1 || !i2 || !i3){
        cout << 0 << '\n';
        return;
    }
    while(l<r){
        //cout << l << ' ' << r << endl;
        mid = (l+r)/2;
        bool can = false;
        vector <int> cnt(3, 0);
        for(int i=0; i<mid; i++){
            cnt[s[i]-'1']++;
        }
        int a = 0, b = mid-1;
        while(b < n){
            if(cnt[0] > 0 && cnt[1] > 0 && cnt[2] > 0){
                can = true; break;
            }
            cnt[s[a]-'1']--;
            a++;
            b++;
            cnt[s[b]-'1']++;
        }
        if(can){
            r = mid;
        }
        else{
            l = mid+1;
        }
    }
    cout << l << '\n';
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while(t--){
        solve();
    }


    return 0;
}
