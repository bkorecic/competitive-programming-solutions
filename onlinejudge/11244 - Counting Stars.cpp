#include <iostream>
using namespace std;
#define MAX_X 100
#define MAX_Y 100
char matriz[MAX_X][MAX_Y]; //x,y

int navegarx[] = {0,-1,-1,-1,0,1,1,1};
int navegary[] = {1,1,0,-1,-1,-1,0,1}; //S, SE, E, NE, N, NO, O, SO

int dfs(int x, int y, int obj, int r) {
    
    if(x < 0 || y < 0 || x >= MAX_X || y >= MAX_Y){
        return 0;
    }
    
    if(matriz[x][y] != obj){
        return 0;
    }
    
    int cuenta = 1;
    
    matriz[x][y] = r;
    
    for(int i = 0; i<8; i++){ 
    
    cuenta+= dfs(x+navegarx[i], y+navegary[i], obj, r);
    
    }
    
    return cuenta;
}

int main() {
    // 11244 - Counting Stars
    int r, c; //rows, columns
    cin >> r >> c;
    while(r!=0 && c!=0){
        //Escribir matriz
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                cin >> matriz[i][j];
            }
        }
        
        //imprimir matriz
        /*
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                cout << matriz[i][j];
            }
            cout << endl;
        }
        */
        
        
        //dfs
        int cuenta = 0;
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                if(dfs(i, j, '*', 'o') == 1){
                    cuenta++;
                }
            }
        }
        
        cout << cuenta << endl;
        
        cin >> r >> c;
    }
    return 0;
}