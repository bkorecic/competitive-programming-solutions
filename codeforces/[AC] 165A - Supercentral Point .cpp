#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second
#define mp make_pair
#define pb push_back

typedef long long ll;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	vector <pair <int, int>> points(n);
	for(int i=0; i<n; i++) cin>>points[i].f>>points[i].s;
	int ans = 0;
	for(int i=0; i<n; i++){
		int actualx = points[i].f;
		int actualy = points[i].s;
		bool up = 0, down = 0, left = 0, right = 0;
		for(int j=0; j<n; j++){
			if(points[j].f > actualx and points[j].s == actualy){
				right = true;
			}
			if(points[j].f < actualx and points[j].s == actualy){
				left = true;
			}
			if(points[j].f == actualx and points[j].s > actualy){
				up = true;
			}
			if(points[j].f == actualx and points[j].s < actualy){
				down = true;
			}
		}
		if(up and down and left and right)ans++;
	}
	cout << ans << '\n';
	return 0;
}
