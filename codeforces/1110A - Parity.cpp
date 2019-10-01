#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;

typedef pair<int, int> ii;

typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ii> vii;

#define mp make_pair
#define pb push_back
#define f first
#define s second

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int b, k; cin >> b >> k;
	vector <int> digits(k,0);
	vector <int> pot(k,0);
	for(int i=0; i<k; i++){
		cin >> digits[i];
	}
	pot[0] = 1;
	for(int i=1; i<k; i++){
		pot[i] = pot[i-1]*b%2;
	}
	int num = 0;
	for(int i=0; i<k; i++){
		num = (num%2 + pot[k-i-1]*digits[i]%2)%2;
	}
	//for(int i=0; i<k; i++){
	//	cout << pot[i] << ' ' << digits[i] << endl;
	//}
	//cout << num << endl;
	if(num == 0) cout << "even\n";
	else cout << "odd\n";
	return 0;
}