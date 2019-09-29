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

int dirx[8] = {0, 0, 1, -1, 1, -1, 1, -1};
int diry[8] = {1, -1, 0, 0, 1, -1, -1, 1}; 
set <string> setAux;
vector <vector <char>> a(4, vector<char>(4));
vector <vector <bool>> visited(4, vector<bool>(4));

void count(int x, int y, int largoActual = 1, int cantVocales = 0, string ans = ""){
	if(x<0 || x>3 || y<0 || y>3)return;
	ans += a[x][y];
	if(a[x][y] == 'A' || a[x][y] == 'E' || a[x][y] == 'I' || 
	   a[x][y] == 'O' || a[x][y] == 'U' || a[x][y] == 'Y'){
		   cantVocales++;
	}
	if(largoActual == 4 && cantVocales == 2){
		setAux.insert(ans);
		return;
	}
	else if(largoActual == 4)return;
	for(int i=0; i<8; i++){
		if(x+dirx[i]>=0 && x+dirx[i] <=3 && y+diry[i] >=0 && y+diry[i] <=3){
			if(visited[x+dirx[i]][y + diry[i]] == false){
				visited[x][y] = true;
				count(x + dirx[i], y + diry[i], largoActual+1, cantVocales, ans);
				visited[x][y] = false;
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	vector <vector <char>> m1(4, vector<char>(4)); 
	vector <vector <char>> m2(4, vector<char>(4));
	char x;
	bool first = true;
	while(cin >> x, x!='#'){
		if(!first)cout << '\n';
		m1[0][0] = x;
		cin >> m1[0][1] >> m1[0][2] >> m1[0][3];
		cin >> m2[0][0] >> m2[0][1] >> m2[0][2] >> m2[0][3];
		for(int i=1; i<=3; i++){
			for(int j=0; j<4; j++)cin >> m1[i][j];
			for(int j=0; j<4; j++)cin >> m2[i][j];
		}
		setAux.clear();
		a = m1;
		for(int i=0; i<4; i++){
			for(int j=0; j<4; j++){
				visited.assign(4, vector<bool>(4,false));
				count(i, j);
			}
		}
		set <string> set1 = setAux;
		setAux.clear();
		a = m2;
		for(int i=0; i<4; i++){
			for(int j=0; j<4; j++){
				visited.assign(4, vector<bool>(4,false));
				count(i, j);
			}
		}
		set <string> set2 = setAux;
		vector <string> ans;
		for(auto it : set1){
			if(set2.find(it) != set2.end())ans.push_back(it);
		}
		sort(ans.begin(),ans.end());
		if(ans.size() == 0){
			cout << "There are no common words for this pair of boggle boards.\n";
		}
		else{
			for(size_t i = 0; i<ans.size(); i++){
				cout << ans[i] << endl;
			}
		}
		
		first = false;
	}
	
	
	return 0;
}
