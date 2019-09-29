#include bitsstdc++.h
using namespace std;
void swapQ(vector char &a, int i1, int i2){
  int aux = a[i1];
  a[i1] = a[i2];
  a[i2] = aux;
  return;
}
int main() {
  266B - Queue at the School
  int N,T; cin  N   T;
  vector char q(N,0);
  for(int i=0; iN; i++){
    cin  q[i];
  }
  
  for(int i=0; iT; i++){
    vector bool swapped(N,false);
    for(int k=0; kN-1; k++){
      if(q[k]=='B' && q[k+1] == 'G' && swapped[k] == false && swapped[k+1] == false){
        swapQ(q,k,k+1);
        swapped[k] = true;
        swapped[k+1] = true;
      }
    }
  }
  
  for(int i=0; iN; i++){
    cout  q[i];
  }
  cout  'n';
  return 0;
}
