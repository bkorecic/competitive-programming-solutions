#include <bits/stdc++.h>
using namespace std;

int main() {
  string line;
  getline(cin,line);
  vector <bool> listed(1e4,false);
  int c = 0;
  for(int i=0; i<line.length(); i++){
    if((int)line[i] >= 97 && (int)line[i] <= 122 && listed[(int)line[i]] == false){
      listed[(int)line[i]] = true;
      c++;
    }
  }
  cout << c << '\n';
  return 0;
}
