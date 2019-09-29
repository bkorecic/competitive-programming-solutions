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
	int N; cin >> N;
	vector <int> num(N);
	vector <char> ans(N,'A');
	vector <int> count(100,0);
	for(int i=0; i<N; i++){
		cin>>num[i];
		count[num[i]]++;
	}
	int nice=0, otros=0;
	for(int i=0; i<100; i++){
		if(count[i]==1)nice++;
		else if(count[i]>2)otros++;
	}
	//cout << "NICE: " << nice << endl;
	//cout << "OTROS: " << otros << endl;
	if(nice%2==0 || otros>0){
		cout << "YES\n";
		int cambiar = nice/2;
		int i=0;
		while(cambiar>0){
			if(count[num[i]] == 1){
				ans[i] = 'B';
				cambiar--;
			}
			i++;
		}
		if(nice%2 != 0){
			for(int j=0; j<N; j++){
				if(count[num[j]]>2){
					ans[j] = 'B';
					break;
				}
			}
		}
		for(int j=0; j<N; j++){
			cout << ans[j];
		}
		cout << '\n';
	}
	else{
		cout << "NO\n";
	}
	
	return 0;
}
