#include <iostream>
#include <vector>
#include <utility>
#include <queue>

using namespace std;

typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

int movx[4] = {1,-1,0,0};
int movy[4] = {0,0,1,-1}; //Derecha, izquierda, arriba, abajo



int main() {
    //10653 - Bombs! NO they are Mines!!
    int sizex, sizey, filasBombas;
    while(cin >> sizex >> sizey){
        if(sizex == 0 && sizey == 0){
            return 0;
        }
        
        int grid[sizex][sizey]; // -10 = unvisited, -1 = bomba, e.o.c = visited
        for(int i=0; i<sizex; i++){
            for(int k=0; k<sizey; k++){
                grid[i][k] = -10;
            }
        }
        cin >> filasBombas;
        for(int i=0; i<filasBombas; i++){
            int coordenada1, coordenada2, tmp;
            cin >> coordenada1 >> tmp;
            for(int i=0; i<tmp; i++){
                cin >> coordenada2;
                grid[coordenada1][coordenada2] = -1;
            }
        }
        
        int xinicial, yinicial, xfinal, yfinal;
        cin >> xinicial >> yinicial >> xfinal >> yfinal;
        
        //BFS
        
        queue<ii> q;
        q.push(make_pair(xinicial,yinicial));
        grid[xinicial][yinicial] = 0;
        while(!q.empty()) {
            
            ii u = q.front();
            q.pop();
            for(int i=0; i<4; i++){
                ii coord = make_pair(u.first+movx[i],u.second+movy[i]);
                if(coord.first < 0 || coord.second < 0 || coord.first >= sizex || coord.second >= sizey){
                    continue; //saltar si se escapa del grid
                }
                int aux = grid[coord.first][coord.second];
                if(aux!=-1 && aux==-10){
                    grid[coord.first][coord.second] = grid[u.first][u.second] + 1;
                    q.push(make_pair(coord.first,coord.second));
                    
                    if(coord.first == xfinal && coord.second == yfinal){
                        for(int c=0; c<q.size(); c++){ //Vaciar cola para romper el while
                            q.pop();
                        }
                        cout << grid[coord.first][coord.second] << endl; //Salida
                        break;
                    }
                    
                }
                
            }
            
        }
        
    }
    
    return 0;
}