#include <iostream>
#include <cmath>
using namespace std;

int main(){
	int n, x, y, a, b;
	cin >> n;
	for(int rep=0; rep<n; rep++) {
		cin >> x >> y;
		a = (x+y)/2;
		b = (x-y)/2;
		if(a>=0 && b>=0 && (x+y)%2 == 0 && (x-y)%2==0){
			cout << max(a,b) << " " << min(a,b) << endl;
		}
		else{
			cout << "impossible" << endl;
		}
	}
return 0;
}

