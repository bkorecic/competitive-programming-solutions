#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
typedef long long ll;

void draw(int P, int N, vector <vector <pair<int,int>>> &players, queue <pair<int,int>> &mazo){
	for(int i=0; i<N; i++){
		pair <int,int> paux;
		paux = mazo.front();
		mazo.pop();
		players[P].push_back(paux); 
	}
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int P, M, N;
	while(cin >> P , P!=0){
		cin >> M >> N;
		queue <pair <int,int>> mazo;
		stack <pair <int,int>> discard;
		vector <vector <pair <int,int>>> players(P);
		int direction = 1;
		int actual = 0;
		//LECTURA MAZO
		for(int i=0; i<N; i++){
			pair <int,int> paux;
			int iaux; char caux;
			cin >> iaux >> caux;
			int ctransf;
			if(caux == 'C')ctransf = 0;
			else if(caux == 'D')ctransf=1;
			else if(caux == 'H')ctransf=2;
			else ctransf=3;
			paux = {iaux, ctransf};
			mazo.push(paux);
		}
		//Variable usada para sacar weas
		pair <int,int> sacar;
		//REPARTIR MANOS
		for(int i=0; i<P; i++){
			for(int k=0; k<M; k++){
				sacar = mazo.front();
				mazo.pop();
				players[i].push_back(sacar);
			}
		}
		sacar = mazo.front();
		mazo.pop();
		discard.push(sacar);
		//EFECTOS PRIMER DISCARD
		if(discard.top().f == 12){
			direction*=-1;
		}
		else if(discard.top().f == 7){
			draw(actual,2,players,mazo);
			actual++;
		}
		else if(discard.top().f == 1){
			draw(actual,1,players,mazo);
			actual++;
		}
		else if(discard.top().f == 11){
			actual++;
		}
		int winner;
		while(1){
			bool discarded = false;
			sort(players[actual].begin(),players[actual].end(),greater<pair<int,int>>());
			// DEBUG: 
			/*
			cout << "PLAYER ACTUAL: " << actual << endl;
			cout << "DISCARD TOP : " << discard.top().f << " " << discard.top().s << endl;
			cout << "MANO PLAYER ACTUAL : " << endl;
			for(int i=0; i<players[actual].size(); i++){
				cout << "||" << players[actual][i].f << " " << players[actual][i].s;
			}
			cout << endl;
			*/
			//DISCARDING:
			for(int i=0; i<players[actual].size(); i++){
				pair <int,int> paux = players[actual][i];
				if(paux.f == discard.top().f || paux.s == discard.top().s){
					discard.push(players[actual][i]);
					players[actual].erase(players[actual].begin() + i);
					discarded = true;
					break;
				}
			}

			if(players[actual].size() == 0){
				winner = actual;
				break;
			}
			if(discarded==false){
				draw(actual,1,players,mazo);
				for(int i=0; i<players[actual].size(); i++){
				pair <int,int> paux = players[actual][i];
				if(paux.f == discard.top().f || paux.s == discard.top().s){
					discard.push(players[actual][i]);
					players[actual].erase(players[actual].begin() + i);
					discarded = true;
					break;
				}
			}

			}
			if(players[actual].size() == 0){
				winner = actual;
				break;
			}
			if(discarded){
				if(discard.top().f == 12){
					direction*=-1;
				}
				else if(discard.top().f == 7){
					if(direction==1){
						draw((actual+1)%P,2,players,mazo);
						actual = (actual+1)%P;
					}
					else {
						draw((actual+P-1)%P,2,players,mazo);
						actual = (actual+P-1)%P;
					}
					
				}
				else if(discard.top().f == 1){
					if(direction==1){
						draw((actual+1)%P,1,players,mazo);
						actual = (actual+1)%P;
					}
					else {
						draw((actual+P-1)%P,1,players,mazo);
						actual = (actual+P-1)%P;
					}
				}
				else if(discard.top().f == 11){
					if(direction==1){
						actual = (actual+1)%P;
					}
					else{
						actual = (actual+P-1)%P;
					}
				}
			}
			if(direction==1){
				actual = (actual+1)%P;
			}
			else{
				actual = (actual+P-1)%P;
			}
		}
		cout << winner+1 << '\n';
	}
	return 0;
}
