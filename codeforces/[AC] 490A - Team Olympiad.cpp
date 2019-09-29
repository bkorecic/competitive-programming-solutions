#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int N; cin >> N;
	vector <int> t1, t2, t3;
	for(int i=0; i<N; i++){
		int aux; cin >> aux;
		if(aux==1)t1.push_back(i);
		else if(aux==2)t2.push_back(i);
		else t3.push_back(i);
	}
	int w = min(min(t1.size(),t2.size()),t3.size());
	cout << w << '\n';
	for(int i=0; i<w; i++){
		cout << t1[i]+1 << " " << t2[i]+1 << " " << t3[i]+1 << '\n';
	}
	return 0;
}