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

vector <set <int>> divisores(10001);
vector <bool> isPrime(10001, true);

struct SegmentTree{
	vector <int> tree;
	int n = 10001;
	SegmentTree(){
		tree.assign(2*n, 0);
	}
	void update(int i, int value){
		i+=n;
		tree[i] = value;
		while(i>1){
			i/=2;
			tree[i] = __gcd(tree[i<<1], tree[i<<1 | 1]);
		}
	}
};

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	//auto start = std::chrono::steady_clock::now();
	isPrime[1] = false;
	for (int i = 2; i < 10001; i++) {
		divisores[i].insert(1);
		if (isPrime[i]) {
			for (int j = i + i; j < 10001; j += i) {
				isPrime[j] = 0;
			}
		}
		else {
			for (int j = i; j < 10001; j += i) {
				divisores[j].insert(i);
			}
		}
	}
	int T; cin >> T;
	for(int rep=0; rep<T; rep++){
		int N; cin >> N;
		SegmentTree ST;
		vector <int> contar(10001, 0);
		for(int i=0; i<N; i++){
			string op; cin >> op;
			if(op == "UPD"){
				cin >> op;
				int value; cin >> value;
				if(op == "ADD"){
					if(contar[value] == 0){
						ST.update(value, value);
					}
					contar[value]++;
				}
				if(op == "REM"){
					if(contar[value] == 1){
						ST.update(value, 0);
					}
					contar[value]--;
				}
			}
			else if(op == "CON"){
				int num = ST.tree[1];
				if(num == 0){
					cout << "-1\n";
				}
				else if(num == 1){
					cout << "1\n";
				}
				else{
					set <int> ans = divisores[num];
					for(auto v : ans){
						if(v != *ans.begin()) cout << ' ';
						cout << v;
					}
					cout << '\n';
				}
			}
		}
	}
	
	//auto finish = std::chrono::steady_clock::now();
	//double elapsed_seconds = std::chrono::duration_cast<
	//std::chrono::duration<double> >(finish - start).count();
	//cout << elapsed_seconds << endl;
	return 0;
}
