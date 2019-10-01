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
	ll n, s; cin >> n >> s;
	vector <ll> kegs(n);
	ll menor = 1e13;
	ll sumaTotal = 0;
	for(int i=0; i<n; i++){
		cin >> kegs[i];
		if(kegs[i] < menor){
			menor = kegs[i];
		} 
		sumaTotal += kegs[i];
	}
	
	if(sumaTotal < s){ //CASO IMPOSIBLE
		cout << "-1\n";
		return 0;
	}
	
	ll mayores_que = 0;
	for(int i=0; i<n; i++){
		if(kegs[i] > menor){
			mayores_que += kegs[i] - menor;
		}
	}
	//binary search
	ll l = 0, r = menor, mid;
	while(l < r){
		mid = (l+r)/2;
		if(mayores_que + n*mid >= s)r = mid;
		else l = mid+1;
	}
	cout << menor - l << endl;
	/*
	cout << "mayores: " << mayores_que << endl;
	for(ll i=0; i<=n; i++){
		if(mayores_que + n*i >= s){
			cout << i << '\n';
			break;
		}
	} */
	return 0;
}