#include <bits/stdc++.h>

using namespace std;

int main(){
	int N; cin >> N;
	vector <int> coins(N);
	int s1=0,s2=0;
	for(int i=0; i<N; i++){
		cin>>coins[i];
		s1+=coins[i];
	}
	sort(coins.begin(),coins.end());
	int c=0;
	while(s1>=s2){
		s1-=coins[N-1];
		s2+=coins[N-1];
		N--;
		c++;
	}
	cout << c << endl;
    return 0;
}