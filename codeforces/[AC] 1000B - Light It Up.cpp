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
	int n, M; cin >> n >> M;
	vector <ll> arr(n+2);
	arr[0] = 0;
	arr[n+1] = M;
	for(int i=1; i<=n; i++)cin>>arr[i];
	vector <ll> dif(n+1);
	for(int i=0; i<n+1; i++){
		dif[i] = arr[i+1] - arr[i];
	}
	vector <ll> pares(n+1);
	vector <ll> impares(n+1);
	ll sumPares = 0;
	ll sumImpares = 0;
	for(int i=0; i<n+1; i++){
		if(i%2==0){
			sumPares+=dif[i];
		}
		else{
			sumImpares+=dif[i];
		}
		pares[i] = sumPares;
		impares[i] = sumImpares;
	} /*
	cout << "ARR: ";
	for(int i=0; i<n+2; i++){
		cout << arr[i] << ' ';
	}cout << '\n';
	cout << "DIF: ";
	for(int i=0; i<n+1; i++){
		cout << dif[i] << ' ';
	}cout << '\n';
	cout << "PARES: ";
	for(int i=0; i<n+1; i++){
		cout << pares[i] << ' ';
	}cout << '\n';
	cout << "IMPARES: ";
	for(int i=0; i<n+1; i++){
		cout << impares[i] << ' ';
	}cout << '\n';
	*/
	ll ans = pares[n];
	for(int i=0; i<n+1; i++){
		ll resta = 0;
		if(i!=0) resta = impares[i-1];
		ll candidato = pares[i] + impares[n] - resta-1;
		//cout << "i= " << i << '\t' << "candidato=" << candidato << '\n';
		if(candidato > ans) ans = candidato;
	}
	cout << ans << '\n';
	
	
	return 0;
}