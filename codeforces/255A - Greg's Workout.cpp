#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	vector <int> count(3,0);
	int N; cin >> N;
	int ans = 0;
	for(int i=0; i<N; i++){
		int aux; cin >> aux;
		count[i%3]+=aux;
		if(count[i%3] > count[ans]) ans = i%3;
	}
	if(ans==0) cout << "chest\n";
	else if(ans==1) cout << "biceps\n";
	else cout << "back\n";
	
	return 0;
}