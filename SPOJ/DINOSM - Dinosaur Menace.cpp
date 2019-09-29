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

vector <vi> AdjList;
vi visited;
	
int dfs_reach(int actual, int obj){
	//Cuando encuentre el nodo que buscamos, si está en la misma componente conexa, sumaremos 1.
	visited[actual] = 1;
	if(actual==obj){
		return 1;
	}
	int sum = 0;
	for(int i=0; i<AdjList[actual].size(); i++){
		if(visited[AdjList[actual][i]] == 0){
			sum+=dfs_reach(AdjList[actual][i],obj);
		}
	}
	return sum;
}

int dfs_reach(int actual, int obj, int N){
	visited.assign(N,0);
	return dfs_reach(actual,obj);
}

bool test(ll &N, ll &W, ll &H, double &M, vii &coord){
	double radio = (double)M;
	//Cálculo de todas las distancias y armado grafo
	AdjList.assign(N+4, vi (0));
	for(int i=0; i<N; i++){
		//up wall / NODE N
		if(abs((double)coord[i].s-(double)H) < (double)radio){
			AdjList[N].pb(i);
			AdjList[i].pb(N);
		}
		//right wall / NODE N+1
		if(abs((double)coord[i].f-(double)W) < (double)radio){
			AdjList[N+1].pb(i);
			AdjList[i].pb(N+1);
		}
		//down wall / NODE N+2
		if((double)coord[i].s < (double)radio){
			AdjList[N+2].pb(i);
			AdjList[i].pb(N+2);
		}
		//left wall / NODE N+3
		if((double)coord[i].f < (double)radio){
			AdjList[N+3].pb(i);
			AdjList[i].pb(N+3);
		}
		//Juntar dos dinosaurios
		for(int j=i+1; j<N; j++){
			double distance = sqrt(((double)coord[i].f - (double)coord[j].f)*((double)coord[i].f - (double)coord[j].f) + ((double)coord[i].s - (double)coord[j].s)*((double)coord[i].s - (double)coord[j].s));
			if(distance/2 <= radio){
				AdjList[i].pb(j);
				AdjList[j].pb(i);
			}
		}
	}
	//DFS up-down
		//cout << "UP DOWN " << dfs_reach(N,N+2,N+4) << endl;
	if(dfs_reach(N,N+2,N+4)==1)return false;
	//DFS up-right
		//cout << "UP RIGHT " << dfs_reach(N,N+1,N+4) << endl;
	if(dfs_reach(N,N+1,N+4)==1)return false;
	//DFS right-left
		//cout << "RIGHT LEFT "<< dfs_reach(N+1,N+3,N+4) << endl;
	if(dfs_reach(N+1,N+3,N+4)==1)return false;
	//DFS down-left
		//cout << "DOWN LEFT " << dfs_reach(N+2,N+3,N+4) << endl;
	if(dfs_reach(N+2,N+3,N+4)==1)return false;
	//Ninguno falso, luego, true:
	return true;
}

int main(){
	ll N, W, H;
	while(cin>>N>>W>>H){
		if(N==-1)break;
		//Lectura coordenadas
		vii coord(N);
		for(int i=0; i<N; i++){
			cin >> coord[i].f >> coord[i].s;
		}
		//
		double R = min(W,H);;//Búsqueda binaria entre L y R, serán los doubles de tres decimales multiplicados por 10000 (para hacer el redondeo al final)
		double L = 0;
		double M = (L+R)/2;
		int precision = 35;
		while(precision--){
			M = (L+R)/2;
			//cout << "L: " << L << " R: " << R << " M: " << M << endl;
			if(test(N,W,H,M, coord)){
				L = M;
			}
			else{
				R = M;
			}
		}
		cout << fixed << setprecision(3) << M << '\n';
	}
	return 0;
}
