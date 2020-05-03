#include <bits/stdc++.h>
#define f first
#define s second
 
using namespace std;
 
typedef long long ll;
 
struct Hash{
    ll MOD; // 1e9+7, 1e9+123
    ll B; // 127, 139
    vector <ll> pot; 
    vector <ll> H;
    int n;
    Hash(){} 
    Hash(string &s, ll _B, ll _MOD){
        n = s.length(); 
        B = _B;
        MOD = _MOD;
        pot.resize(n+1);
        H.resize(n);
        H[n-1] = s[n-1];
        for(int i = n-2; i>=0; i--){
            H[i] = (s[i] + H[i+1]*B)%MOD;
        }
        pot[0] = 1;
        for(int i=1; i<n+1; i++){
            pot[i] = (pot[i-1]*B)%MOD;
        }
    }
    ll hash(int i, int j){
        ll resta;
        if(j == n-1) resta = 0;
        else resta = H[j+1]*pot[j-i+1]%MOD;
        return (H[i] - resta + MOD)%MOD;
    }
};
 
Hash h, rh;
int n;
 
bool is_palindrome(int i, int j){
    return h.hash(i,j) == rh.hash(n-1-j, n-1-i);  
}
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while(t--){
        string s; cin >> s;
        n = s.size();
        h = Hash(s, 127, 1e9+7);
        string rs = s;
        reverse(rs.begin(), rs.end());
        rh = Hash(rs, 127, 1e9+7);
        int l = 0, r = n-1;
        while(s[l] == s[r] && l < r){
            l++; r--;
        }
        if(l==r){
            cout << s << '\n';
            continue;
        }
        // palindromo mas grande que empieza en l,
        // palindromo mas grande que termina en r
        int max_len = 0;
        int ind_ans = 0;
        // l ->
        int i, j;
        i = l;
        for(j = l; j <= r; j++){
            if(is_palindrome(i,j)){
                int len = j-i+1;
                if(len > max_len){
                    ind_ans = i;
                    max_len = len;
                }
            }
        }
 
        // <- j
        j = r;
        for(i = r; i >= l; i--){
            if(is_palindrome(i,j)){
                int len = j-i+1;
                if(len > max_len){
                    ind_ans = i;
                    max_len = len;
                }
            }
        }
        string ans;
        if(l > 0){
            ans = s.substr(0,l) + s.substr(ind_ans,max_len) + s.substr(r+1, l);
        }
        else{
            ans = s.substr(ind_ans,max_len);
        }
        cout << ans << '\n';
        //cout << l << ' ' << r << endl;
        //cout << ind_ans << ' ' << max_len << endl;
 
    }
 
    return 0;
}