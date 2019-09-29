#include <iostream>
using namespace std;

int main() {
  //RECTANGL - Rectangle
  int N, a, b, c, d;
  cin >> N;
  for(int i=0; i<N; i++){
    cin >> a >> b >> c >> d;
    if(a==b && c==d){
      cout << "YES" << endl;
    }
    else if(a==c && b==d){
      cout << "YES" << endl;
    }
    else if(a==d && b==c){
      cout << "YES" << endl;
    }
    else{
      cout << "NO" << endl;
    }
  }
  return 0;
}