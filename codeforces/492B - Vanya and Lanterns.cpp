#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int N, L; cin >> N >> L;
	vector <int> lanterns(N);
	for(int i=0; i<N; i++)cin>>lanterns[i];
	sort(lanterns.begin(),lanterns.end());
	vector <double> distances(N+1);
	distances[0] = (double)lanterns[0];
	distances[N] = (double)L - (double)lanterns[N-1];
	for(int i=1; i<N; i++){
		distances[i] = ((double)lanterns[i] - (double)lanterns[i-1])/2;
	}
	double ans = -1;
	for(int i=0; i<N+1; i++)if(distances[i] > ans) ans = distances[i];
	cout << fixed << setprecision(9) << ans << '\n';
	return 0;
}