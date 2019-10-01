#include <bits/stdc++.h>
using namespace std;

int main() {
  string n;
  getline(cin,n);
  bool space = false;
  for(int i=0; i<n.length(); i+=0){
    if(n[i] == 'W' && i<n.length()-2){
      if(n[i+1] == 'U' && n[i+2] == 'B'){
        i+=3;
        space = true;
      }
      else{
        if(space==true)cout<<' ';
        space = false;
        cout << n[i];
        i++;
      }
    }
    else{
      if(space==true)cout<<' ';
      space = false;
      cout << n[i];
      i++;
    } 
  }
  cout << '\n';
  
  return 0;
}
