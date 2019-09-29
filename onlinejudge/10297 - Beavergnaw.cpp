#include <bits/stdc++.h> 
using namespace std; 
int main(){
	double D, V;
	double pi = acos(-1.0);
	while(cin>>D >> V, D != 0){
		double d = cbrt(D*D*D - (6*V)/pi);
		cout << fixed << setprecision(3) << d << '\n';
	}   
 	return 0;
}