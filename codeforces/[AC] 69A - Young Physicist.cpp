#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, c=0, x=0,y=0,z=0; 
  cin >> N;
  for(int i=0; i<N; i++){
    int a1,a2,a3;
    cin >> a1 >> a2 >> a3;
    x+=a1; y+=a2; z+=a3;
  }
  if(!x && !y && !z)cout<<"YES\n";
  else cout<<"NO\n";
  return 0;
}
