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

ll N;
vector <ll> digits;
vector <int> used;
int size;
bool done;
bool pos;

void backtrack(ll actual1 = 0, ll actual2 = 0, ll depth = 1, int last1 = -1, int last2 = -1){
	if(done)return;
	if(actual1*actual2 > N)return;
	if(actual1*actual2 == N && (int)log10(actual1) == (int)log10(actual2)){
		done = true;
		pos = true;
		return;
	}
	for(int i=0; i<=9; i++){
		if(i==0 && (last1==0 || depth==size-1))continue;
		if(used[i] == 0)continue;
		for(int j=0; j<=9; j++){
			if(done)return;
			if(used[j] == 0)continue;
			if(i==j && used[j] == 1)continue;
			if(j==0 && (last2==0 || depth==size-1))continue;
			ll aux1 = actual1 + i*pow(10,depth-1);
			ll aux2 = actual2 + j*pow(10,depth-1);
			used[i]--;
			used[j]--;
			if((aux1*aux2)%(ll)pow(10,depth) == digits[size-depth]){
				backtrack(aux1, aux2, depth + 1, i, j);
			}
			used[i]++;
			used[j]++;
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	while(cin >> N, N != 0){
		pos = false;
		done = false;
		size = log10(N) + 1;
		digits.assign(size, 0);
		digits[0] = N;
		for(int i=1; i<size; i++){
			digits[i] = digits[i-1]%(ll)pow(10,size-i);
		}
		used.assign(10, 0);
		ll Naux = N;
		while(Naux!=0){
			used[Naux%10]++;
			Naux/=10;
		}
		backtrack();
		if(pos)cout << N << ": yes" << endl;
		else cout << N << ": no" << endl;
	}
	return 0;
}
