#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int N; cin >> N;
	vector <int> sarr(N);
	for(int i=0; i<N; i++) cin >> sarr[i];
	vector <int> arr = sarr;
	sort(sarr.begin(),sarr.end());
	int diff = 0;
	int l, r;
	for(int i=0; i<N; i++){
		//cout << "i = " << i << endl;
		if(arr[i] != sarr[i]){
			//cout << "Diferencia en i = " << i << endl;
			int pos;
			diff++;
			for(int k=i; k<N; k++){
				if(sarr[k] == arr[i]){
					pos = k;
					//cout << "pos encontrado en " << k << endl;
					break;
				}
			}
			for (int k=0; k<pos-i+1; k++){
				if(arr[i+k] != sarr[pos-k]){
					cout << "no\n";
					return 0;	
				}
			}
			l = i;
			r = pos;
			i=pos;
		}
	}
	if(diff==1){
		cout << "yes\n" << l+1 << " " << r+1 << '\n';
	}
	else if (diff==0) cout << "yes\n1 1\n";
	else cout << "no\n";
	return 0;
}