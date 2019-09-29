#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;

int main() {
  long long N, M; cin >> N >> M;
  
  long long suma = 0;
  long long actual = 1;
  
  for(int i=0; i<M; i++){
    long long next; cin >> next;
    if(next>=actual){
      suma += next-actual;
      actual = next;
    }
    else if(next<actual){
      suma+=(N-actual) + (next);
      actual = next;
    }
  }
  cout << suma << '\n';
  return 0;
}
