#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second
#define mp make_pair
#define pb push_back

typedef long long ll;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int a, b, c, d; cin >> a >> b >> c >> d;
	int misha = max(3*a/10, a - (a/250)*c);
	int vasya = max(3*b/10, b - (b/250)*d);
	if(misha > vasya){
		cout << "Misha\n";
	}
	else if(vasya > misha){
		cout << "Vasya\n";
	}
	else cout << "Tie\n";
	
	return 0;
}