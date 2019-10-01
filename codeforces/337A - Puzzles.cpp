#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M; cin >> N >> M;
  vector <int> p(M);
  for(int i=0; i<M; i++){
    cin >> p[i];
  }
  sort(p.begin(),p.end());
  vector <int> differences(M-N+1);
  for(int i=0; i<M-N+1; i++){
    differences[i] = p[N+i-1] - p[i];
  }
  cout << *min_element(differences.begin(),differences.end()) << '\n';
  return 0;
}
