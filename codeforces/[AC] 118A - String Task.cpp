#include <bits/stdc++.h>

using namespace std;

int main(){
    string a; cin>>a;
    int len = a.length();
    
    for(int i=0; i<len; i++){
        if(a[i]=='A'||a[i]=='E'||a[i]=='I'||a[i]=='O'||a[i]=='U'||a[i]=='Y')continue;
        if(a[i]=='a'||a[i]=='e'||a[i]=='i'||a[i]=='o'||a[i]=='u'||a[i]=='y')continue;
        cout << ".";
        if((int)a[i] <= 90){
        	a[i] = (int)a[i] + 32;
        	cout << a[i];
        	continue;
        }
        cout << a[i];
    }
    return 0;
}