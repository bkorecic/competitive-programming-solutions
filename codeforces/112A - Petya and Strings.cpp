#include <bits/stdc++.h>

using namespace std;

int main(){
    string a,b; cin >> a >> b;
    int len = a.length();
    for(int i=0; i<len; i++){
    	if((int)a[i] <= 90){
    		a[i] = (int)a[i] + 32;
    	}
    	if((int)b[i] <= 90){
    		b[i] = (int)b[i] + 32;
    	}
    }

    for(int i=0; i<len; i++){
    	if((int)a[i] < (int)b[i]){
    		cout << -1 << endl;
    		return 0;
    	}
    	if((int)a[i] > (int)b[i]){
    		cout << 1 << endl;
    		return 0;
    	}
    	continue;
    }
    cout << 0 << endl;
    return 0;
}