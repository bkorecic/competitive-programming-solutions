#include <bits/stdc++.h>
using namespace std;

int main() {
  int matriz[5][5];
  int a,b;
  for(int i=0; i<5; i++){
    for(int k=0; k<5; k++){
      int aux; cin >> aux;
      matriz[i][k] = aux;
      if(aux==1){
        a=i;
        b=k;
      }
    }
  }
  cout << abs(a-2) + abs(b-2) << '\n'; 
  return 0;
}