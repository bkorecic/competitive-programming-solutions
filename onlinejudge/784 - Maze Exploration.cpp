#include <iostream>
#include <vector>
#include <string>

using namespace std;



char grilla[30][80];

int mFilas[8] = {1, 1, 0,-1,-1,-1, 0, 1}; // S,SE,E,NE,N,NW,W,SW
int mColumnas[8] = {0, 1, 1, 1, 0,-1,-1,-1}; // S,SE,E,NE,N,NW,W,SW


void floodfill(int x, int y, char buscar, char pintar) {
     
    if (x < 0 || x >= 30 || y < 0 || y >= 80) {
        return;
    }
  
    if (grilla[x][y] != buscar) {
        return;
    }
  
    grilla[x][y] = pintar;

    for (int i = 0; i < 8; ++i) {
        floodfill(x + mFilas[i], y + mColumnas[i], buscar, pintar);
    }
    
    return;
  
}

int main() {
  //784 - Maze Exploration  
  
  int N;
  cin >> N;
  getchar();
  
  for(int rep=0; rep<N; rep++){
  
    //Lectura
    
    int index = 0;
    int inicialX;
    int inicialY;
    string linea;
    getline(cin,linea);
    int tamLineas[30];
    while(linea[0] != '_'){
      for(int i=0; i<linea.length(); i++){
        grilla[index][i] = linea[i];
        if(linea[i] == '*'){
          inicialX = index;
          inicialY = i;
          grilla[index][i] = ' ';
        }
      }
      tamLineas[index] = linea.length();
      index++;
      getline(cin,linea);
    }
    
    floodfill(inicialX,inicialY,' ','#');
    
    //Test
    for(int i=0; i<index; i++){
      for(int k=0; k<tamLineas[i]; k++){
        cout<< grilla[i][k];
      }
      cout<<endl;      
    }
    cout << linea << endl;
    
  }
  
  return 0;
}
