#include <iostream>
using namespace std;

int main() {
  int n,m; cin >> n >> m;
  int flag = 1;
  while(n>0 && m>0){
    flag*=-1;
    n--;
    m--;
  }
  if(flag==-1)cout<<"Akshat\n";
  else cout<<"Malvika\n";
  return 0;
}
