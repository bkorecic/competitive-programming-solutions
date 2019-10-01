#include <bits/stdc++.h>
using namespace std;

int main() {
  int x1, x2, y1, y2;
  cin >> x1 >> y1 >> x2 >> y2;
  if(x1 == x2){
    int dif = abs(y1-y2);
    int x3 = x1 + dif;
    int x4 = x2 + dif;
    int y3 = y1;
    int y4 = y2;
    cout << x3 << " " << y3 << " " << x4 << " " << y4 << '\n';
    return 0;
  }
  else if(y1==y2){
    int dif = abs(x1-x2);
    int x3 = x1;
    int x4 = x2;
    int y3 = y1 + dif;
    int y4 = y2 + dif;
    cout << x3 << " " << y3 << " " << x4 << " " << y4 << '\n';
    return 0;
  }
  else if(abs(x1-x2) == abs(y1-y2)){
    cout << x1 << " " << y2 << " " << x2 << " " << y1 << '\n';
    return 0;
  }
  else{
    cout << "-1\n";
    return 0;
  }
  return 0;
}
