#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector <int> n1(N+1),n2(N+1);
  
  for(int i=1; i<=N; i++){
    cin >> n1[i];
    n2[n1[i]] = i;
  }
  
  for(int i=1; i<=N; i++){
    cout << n2[i] << " ";
  }
  cout<<'\n';
  return 0;
}