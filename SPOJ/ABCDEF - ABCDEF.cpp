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
    vector <ll> s(n);
    for(int i=0; i<n; i++) cin >> s[i];
    unordered_map <ll, ll> abc;
    unordered_map <ll, ll> def;
    for(ll a : s)
        for(ll b : s)
            for (ll c : s){
                ll x = a*b+c;
                if(abc.find(x) == abc.end()) abc[x] = 1;
                else abc[x]++;
            }

    for(ll d : s){
        if(d==0) continue;
        for(ll e : s)
            for (ll f : s){
                ll x = d*(e+f);
                if(def.find(x) == def.end()) def[x] = 1;
                else def[x]++;
            }
    }
    ll ans = 0;
    for(auto p : abc){
        if(def.find(p.f) != def.end())
            ans += p.s*def[p.f];
    }
    cout << ans << '\n';
    return 0;
}
