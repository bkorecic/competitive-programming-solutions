#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    long long a, b, s, sum;
    cin >> a >> b >> s;
    sum = abs(a) + abs(b);
    if(s >= sum && s%2 == sum%2){
        cout << "Yes\n";
    }
    else{
        cout << "No\n";
    }
    return 0;
}
