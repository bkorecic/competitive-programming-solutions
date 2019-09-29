#include <iostream>
using namespace std;

int main() {
  int N, M, dos, uno, pasos;
  cin >> N >> M;
  if(N%2==0){
    uno = 0;
    dos = N/2;
  }
  else{
    uno = 1;
    dos = (N-1)/2;
  }
  pasos = uno+dos;
  while(pasos%M != 0){
    if(dos == 0){
      pasos = -1;
      break;
    }
    dos--;
    pasos++;
  }
  cout << pasos << '\n';
  return 0;
}
