#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;

typedef pair<int, int> ii;

typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ii> vii;

#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define EPS 1-e6
#define INF 1e6
#define PI acos(-1.0)

#define mp make_pair
#define pb push_back
#define f first
#define s second

string bigSum(string a, string b){
	if(a.length()<b.length())swap(a,b); //a es el más largo    sum - (sum-10)
	int r = 0;
	string fill(a.length()-b.length(),'0');
	b = fill + b;
    for(int i=a.length()-1; i>=0; i--){
        a[i]+=(b[i]-'0'+r);
		if(a[i]-'0'>=10){
			a[i]-=10;
			r = 1;	
		}
		else r = 0;
	}
	if(r==1){
		return '1'+a;
	}
	else return a;
}

string bigMultiply(string a, string b){
	if(a.length()<b.length())swap(a,b); // a es el más largo
	string ans_f = "0";
	int zeros = 0;
	for(int i=b.length()-1; i>=0; i--){
		string ans_1 = a;
		int d1 = b[i] - '0';
		int r = 0;
		for(int j = ans_1.length()-1; j>=0; j--){
			int d2 = ans_1[j] - '0';
			int mult = d1*d2;
			ans_1[j] = '0'+(mult+r)%10;
			r = (mult+r)/10;
		}
		if(r!=0){
			char c_1 = '0' + r;
			ans_1 = c_1 + ans_1;
		}
		string end(zeros,'0');
		ans_1 += end;
		ans_f = bigSum(ans_f, ans_1);
		zeros++;
	}
	return ans_f;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int a;
	vector <string> mem (367);
	mem[0] = "1";
	for(int i=1; i<=366; i++){
		mem[i] = bigMultiply(mem[i-1], to_string(i));
	}
	while(cin >> a, a != 0){
		string s = mem[a];
		vector <int> count(10,0);
		for(int i=0; i<s.length(); i++){
			count[s[i] - '0']++;
		}
		//formateo de output
		cout << a << "! --\n";
		for(int i=0; i<5; i++){
			cout << "   (" << i << ')';
			if(count[i]<10){
				cout << "    " << count[i];
			}
			else if(count[i]<100){
				cout << "   " << count[i];
			}
			else {
				cout << "  " << count[i];
			}
			if(i!=4) cout << ' ';
		}
		cout << '\n';
		for(int i=5; i<10; i++){
			cout << "   (" << i << ')';
			if(count[i]<10){
				cout << "    " << count[i];
			}
			else if(count[i]<100){
				cout << "   " << count[i];
			}
			else {
				cout << "  " << count[i];
			}
			if(i!=9) cout << ' ';
		}
		cout << '\n';
	}
	return 0;
}
