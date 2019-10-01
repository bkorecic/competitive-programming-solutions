#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;

typedef pair<int, int> ii;

typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ii> vii;

#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)

#define mp make_pair
#define pb push_back
#define f first
#define s second

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int m, n; cin >> m >> n; //rows,columns
	int matrix[m][n];
	int ans[m][n];
	bool uno = false;
	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++){
			cin >> matrix[i][j];
			ans[i][j] = matrix[i][j];
			if(matrix[i][j] == 1)uno=true;
		}
	}
	vector <int> sum_rows(m,0), sum_cols(n,0);
	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++){
			sum_rows[i]+=matrix[i][j];
			sum_cols[j]+=matrix[i][j];
		}
	}
	bool possible = true;
	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++){
			if(matrix[i][j] == 1 && sum_rows[i] != n && sum_cols[j] != m)possible=false;
		}
	}
	if(uno){
		for(int i=0; i<m; i++){
			if(sum_rows[i] == 0)possible=false;
		}
		for(int i=0; i<n; i++){
			if(sum_cols[i] == 0)possible=false;
		}
	}
	if(possible){
		cout << "YES\n";
		for(int i=0; i<m; i++){
			if(sum_rows[i] < n){
				for(int k=0; k<n; k++){
					ans[i][k] = 0;
				}
			}
		}
		for(int j=0; j<n; j++){
			if(sum_cols[j] < m){
				for(int k=0; k<m; k++){
					ans[k][j] = 0;
				}
			}
		}
		for(int i=0; i<m; i++){
			if(i!=0)cout << '\n';
			for(int j=0; j<n; j++){
				if(j!=0)cout << ' ';
				cout << ans[i][j];
			}
		}
	}
	else{
		cout << "NO\n";
	}
	return 0;
}
