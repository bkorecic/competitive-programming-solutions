#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;

int main() {
  int N; cin >> N;
  vector <pair<int,int>> teams(N);
  for(int i=0; i<N; i++){
    cin >> teams[i].f >> teams[i].s;
  }
  int c = 0;
  for(int i=0; i<N; i++){
    for(int j=0; j<N; j++){
      if(teams[i].f == teams[j].s && i!=j)c++;
    }
  }
  cout << c << '\n';
  
  return 0;
}
