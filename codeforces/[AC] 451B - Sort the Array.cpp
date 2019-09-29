#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int m, s; cin >> m >> s;
	if(s>9*m || (s==0 && m>1)){
		cout << "-1 -1\n";
		return 0;
	}
	vector <int> numero(m,0);
	int i = 0;
	while(s>=9){
		numero[i] = 9;
		i++;
		s-=9;
	}
	numero[i] = s;
	for(int i=0; i<m; i++){
		cout << numero[m-1-i];	
	}
	cout << " ";
	for(int i=0; i<m; i++){
		cout << numero[i];
	}
	cout << '\n';
}