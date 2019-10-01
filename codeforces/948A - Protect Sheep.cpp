#include <bits/stdc++.h>
using namespace std;

int main() {
  int R,C; cin >> R >> C;
  int X[4] = {0,1,-1,0};
  int Y[4] = {1,0,0,-1};
  char grilla[R][C];
  for(int i=0; i<R; i++){
    for(int k=0; k<C; k++){
      cin >> grilla[i][k];
    }
  }
  //
  
  for(int i=0; i<R; i++){
    
    for(int k=0; k<C; k++){
      
      if(grilla[i][k] == 'W'){
        
        for(int l=0; l<4; l++){
          
          if(i+X[l] > R-1 || i+X[l] < 0 || k+Y[l] > C-1 || k+Y[l] < 0 || grilla[i+X[l]][k+Y[l]] == 'W')continue;
          
          if(grilla[i+X[l]][k+Y[l]] == 'S'){
            cout << "No" << endl;
            return 0;
          }
          else{
            grilla[i+X[l]][k+Y[l]] = 'D';
          }
          
        }
      }
    }
  }
  
  cout << "Yes" << endl;
  for(int i=0; i<R; i++){
    for(int k=0; k<C; k++){
      cout << grilla[i][k];
    }
    cout << endl;
  }
  
  return 0;
}