#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int N, M; cin >> N >> M;
	bool line = true, row = false;
	for(int x=0; x<N; x++){
		if(line==true){
			for(int i=0; i<M; i++){
				cout << '#';
			}
			line = false;
		}
		else{
			if(row==true){
				cout << '#';
				for(int i=0; i<M-1; i++){
					cout << '.';
				}
				row = false;
			}
			else{
				for(int i=0; i<M-1; i++){
					cout << '.';
				}
				cout << '#';
				row = true;
			}
			line = true;
		}
		cout << '\n';
	}
	return 0;
}