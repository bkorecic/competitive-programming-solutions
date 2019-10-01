#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second
typedef long long ll;
typedef pair<int,int> ii;
typedef vector <int> vi;

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	int n, m; cin >> n >> m;
	vector <vi> A(n, vector<int>(m));
	vector <vi> B(n, vector<int>(m));
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cin >> A[i][j];
		}
	}
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cin >> B[i][j];
		}
	}
	
	bool ans = true;
	int i = 0, j = 0;
	while(j < m){
		//cout << "loop " << i << ' ' << j << endl;
		int i2 = i, j2 = j;
		vector <int> diagA;
		vector <int> diagB;
		while(i2 >= 0 && j2 < m){
			diagA.push_back(A[i2][j2]);
			diagB.push_back(B[i2][j2]);
			i2--; j2++;
		}
		sort(diagA.begin(), diagA.end());
		sort(diagB.begin(), diagB.end()); /*
		cout << "diagA: ";
		for(int k=0; k<diagA.size(); k++){
			cout << diagA[k] << ' ';
		} cout << endl;
		
		cout << "diagB: ";
		for(int k=0; k<diagB.size(); k++){
			cout << diagB[k] << ' ';
		} cout << endl;
		*/
		if(diagA != diagB){
			cout << "NO\n";
			return 0;
		}
		if(i<n-1)i++;
		else j++;
	}
	cout << "YES\n";
	return 0;
}