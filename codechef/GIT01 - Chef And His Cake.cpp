#include <iostream>
#include <cmath>
using namespace std;

int main() {
  //Chef And his Cake
  
  //R>G, 5
  //G>R, 3
  
  int rep, N, M; //N lineas de M largo
  cin >> rep;
  
  for(int i=0; i<rep; i++){
    cin >> N >> M;
    char matriz[N][M];
    //Lectura
    for(int i=0; i<N; i++){
      for(int k=0; k<M; k++){
        cin >> matriz[i][k];
      }
    }
    
    //Dos sumas distintas, una para RGRGRG... y otra para GRGRGRG...
    
    int suma1, suma2;
    suma1 = 0;
    suma2 = 0;
    
    //En suma1, que flag valga 1 significa que debería ser rojo y -1 verde.
    //En suma2, que flag valga 1 significa que debería ser verde y -1 rojo.
    int flag = 1;
    for(int i=0; i<N; i++){
      for(int k=0; k<M; k++){
        if(matriz[i][k] == 'R' && flag == -1){
          suma1+=5;
        }
        if(matriz[i][k] == 'R' && flag == 1){
          suma2+=5;
        }
        if(matriz[i][k] == 'G' && flag == 1){
          suma1+=3;
        }
        if(matriz[i][k] == 'G' && flag == -1){
          suma2+=3;
        }
        flag = flag * -1;
      }
      if(M%2 == 0){
        flag = flag * -1; 
      }
    }
    cout << min(suma1,suma2) << endl;
    
  }
  
  return 0;
}
