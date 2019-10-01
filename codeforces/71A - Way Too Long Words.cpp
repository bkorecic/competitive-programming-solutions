#include <bits/stdc++.h>
using namespace std;

int main(){
    int N; cin>>N;
    for(int i=0; i<N; i++){
        string a; cin >> a;
        int len = a.length();
        if(len>10){
            cout<<a[0]<<len-2<<a[len-1]<<endl;
        }
        else{
            cout << a << endl;
        }
    }
    return 0;
}