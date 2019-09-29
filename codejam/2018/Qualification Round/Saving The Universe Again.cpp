#include <bits/stdc++.h>
using namespace std;

int main(){
	long long T; cin >> T;
	for(long long rep=0; rep<T; rep++){
		int D; string P; cin >> D >> P;
		
		int stotal = 0;
		int dmax = 0, beam = 1;
		for(int i=0; i<P.length(); i++){
			if(P[i]=='C'){
				beam*=2;
			}
			else{
				stotal++;
				dmax+=beam;
			}
		}
		int hacks = 0;
		while(dmax>D){
                int te = dmax/stotal;
                if((double(dmax)/double(stotal)>te))te++;
                if(te%2 != 0)te++;
                dmax -= te/2;
                hacks++;
		}
		
		if(stotal<=D){
			cout << "Case #" << rep+1 << ": " << hacks << '\n';
		}
		else{
			cout << "Case #" << rep+1 << ": IMPOSSIBLE\n";
		}
	}
	return 0;
}