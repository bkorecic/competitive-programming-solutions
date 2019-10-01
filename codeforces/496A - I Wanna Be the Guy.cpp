#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, x, y; cin >> N;
  vector <int> levels(N+1,0);
  cin >> x;
  for(int i=0; i<x; i++){
	int aux; cin >> aux;
    levels[aux] = aux;
  }
  cin >> y;
  for(int i=0; i<y; i++){
    int aux; cin >> aux;
    levels[aux] = aux;
  }
  
  for(int i=1; i<=N; i++){
    if(!levels[i]){
      cout << "Oh, my keyboard!\n";
      return 0;
    }
  }
  cout << "I become the guy.\n";
  return 0;
}