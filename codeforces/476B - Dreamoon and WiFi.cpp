#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int fact(int x){
    int ans = 1;
    for(int i=2; i<=x; i++){
        ans*=i;
    }
    return ans;
}

int comb(int n, int k){
    return (fact(n)/fact(n-k))/fact(k);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    string a, b;
    cin >> a >> b;
    int len = a.size();
    int n=0;
    int a_sum = 0;
    int b_sum = 0;
    for(int i=0; i<len; i++){
        if(a[i] == '+') a_sum++;
        else if(a[i] == '-') a_sum--;

        if(b[i] == '+') b_sum++;
        else if(b[i] == '-') b_sum--;
        else if(b[i] == '?') n++;
    }
    int x = abs(a_sum - b_sum);
    if(n==0){
        if(a_sum == b_sum) cout << 1 << '\n';
        else cout << 0 << '\n';
        return 0;
    }
    if((n+x)%2 == 0){
        int k = (n+x)/2; 
        double ans = (double)comb(n,k);
        for(int i=0; i<n; i++) ans/=2;
        cout << fixed << setprecision(10) << ans << '\n';
    }
    else{
        cout << 0 << '\n';
    }
    return 0;
}
