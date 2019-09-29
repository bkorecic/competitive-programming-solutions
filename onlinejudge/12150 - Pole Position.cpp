#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second

int main(){
	ios_base::sync_with_stdio(0);
	int N;
	while(cin >> N, N!=0){
		vector <pair <int,int>> final(N);
		for(int i=0; i<N; i++)cin >> final[i].f >> final[i].s;
		vector <int> inicial(N, -1);
		for(int i=0; i<N; i++){
			if(i+final[i].s>=0 && i+final[i].s<N){
				inicial[i+final[i].s] = final[i].f;
			}
		}
		bool pos = true;
		for(int i=0; i<N; i++){
			if(inicial[i] == -1)pos=false;
		}
		if(pos){
			for(int i=0; i<N; i++){
				if(i!=0)cout << ' ';
				cout << inicial[i];
			}
			cout << '\n';
		}
		else{
			cout << "-1\n";
		}
	}
	return 0;
}
